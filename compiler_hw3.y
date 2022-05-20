/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_hw_common.h" //Extern variables that communicate with lex
    #include "mySymbolTable.h"
    #include "myCodeGen.h"
    #include "mySwitch.h"
    //#define YYDEBUG 1
    //int yydebug = 1;
    char* free_cat(char*a,char*b){
        int n=strlen(a)+strlen(b)+1;
        char* ret=malloc(n);
        strcpy(ret,a);
        strcat(ret,b);
        free(a);
        free(b);
        return ret;
    }
    char* cdup(char c){
        static char temp[2];
        temp[1]=0;
        temp[0]=c;
        return strdup(temp);
    }
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    int reduce_line=1;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", reduce_line, s);
        g_has_error=true;
    }

    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */

    /* Global variables */
    bool g_has_error = false;
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    char* str_lit;
    int int_lit;
    float float_lit;
    bool bool_lit;
    char* func_sig;
    char* name;
    unsigned char type;
    int label;
    struct forloop_node for_labels;
    struct case_node case_data;
    struct switch_node switch_data;
    /* ... */
}

/* Token without return */
%token VAR NEWLINE
%token INT FLOAT BOOL STRING
%token INC DEC 
%token GEQ LOR LAND EQL
%token ADD_ASSIGN SUB_ASSIGN QUO_ASSIGN MUL_ASSIGN REM_ASSIGN
%token IF ELSE FOR SWITCH CASE DEFAULT
%token PRINTLN PACKAGE FUNC PRINT RETURN

/* Token with return, which need to sepcify type */
%token <int_lit> INT_LIT
%token <float_lit> FLOAT_LIT
%token <str_lit> STRING_LIT 
%token <bool_lit> BOOL_LIT
%token <name> IDENT

%type <type> expr fac term int_lit float_lit bool_lit equ_expr cmp_expr land_expr lor_expr string_lit ident dec_assign
%type <type> type nonvoid_type exprable_type
%type <func_sig> paradec paradecs paradecstart
%type <name> funchead
%type <label> for ifbody ifblockelsebody

%type <for_labels> forbody
%type <case_data> casebody defaultbody
%type <switch_data> switchhalfblock
%type <int_lit> case_lit

%start Program

%%
newline
    : NEWLINE {
        reduce_line++;
    }
;
for
    : FOR {
        $$=label_cnt++;
        LABELGEN($$);
    }
ident
    : IDENT {
        $$=myload($1);
    }
;
Program
    : newlines package methods {

    }
;
package
    : PACKAGE IDENT {
        code_begin();
    }
;

methods
    : method newline methods
    | method
;
method
    : funcbody newlines '{' lines '}' {
        dump_symbol();
        method_end();
    } 
    |
;
lines 
    : line newline lines
    | line
;
newlines
    : newline newlines
    |
;
int_lit
    : INT_LIT {
        $$=type_i;
        CODEGEN("ldc %d\n",$1);
    }
;
float_lit
    : FLOAT_LIT {
        $$=type_f;
        CODEGEN("ldc %f\n",$1);
    }
;
bool_lit
    : BOOL_LIT {
        $$=type_b;
        if($1){
            CODEGEN("iconst_1\n");
        }else{
            CODEGEN("iconst_0\n");
        }
    }
;
string_lit
    : '"' STRING_LIT '"' {
        $$=type_s;
        CODEGEN("ldc \"%s\"\n",$2);
    }
;
parastart
    : paras
    |
;
paras
    : paras ',' lor_expr 
    | lor_expr
;
paradecstart
    : paradecs {
        $$=$1;
    }
    | {
        $$=strdup("");
    }
;
paradecs
    : paradecs ',' paradec {
        $$=free_cat($1,$3);
    }
    | paradec {
        $$=$1;
    }
;
exprable_type
    : INT {
        $$=type_i;
    }
    | FLOAT {
        $$=type_f;
    }
    | BOOL {
        $$=type_b;
    }
;
nonvoid_type
    : exprable_type {
        $$=$1;
    }
    | STRING {
        $$=type_s;
    }
;
type
    : nonvoid_type {
        $$=$1;
    }
    | {
        $$=type_void;
    }
paradec
    : IDENT nonvoid_type {
        reduce_line++;
        insert_symbol($1,$2);
        reduce_line--;
        $$=cdup(get_type($2));
    }
;
funchead
    : FUNC IDENT {
        create_symbol();
        $$=$2;
    }
;
funcbody
    : funchead '(' paradecstart ')' type {
        if(strcmp($1,"main")==0&&strcmp($3,"")==0&&$5==type_void){
            main_method_begin();
        }else{
            method_begin($1,$3,$5);
        }
    }
;
blockbody
    : {
        create_symbol();
    }
;
dec_assign
    : '=' lor_expr {
        $$=$2;
    }
    | {
        $$=type_void;
    }
;
forbody
    : for lor_expr {
        $$.again=$1;
        $$.out=label_cnt++;
        CODEGEN("ifeq Label%d\n",$$.out);
        check_bool_condition($2);
        create_symbol();
    }
;
ifbody
    : IF lor_expr {
        check_bool_condition($2);
        $$=label_cnt++;
        CODEGEN("ifeq Label%d\n",$$);
        create_symbol();
    }
;
ifblockelsebody
    : ifbody newlines '{' lines '}' ELSE {
        $$=label_cnt++;
        dump_symbol();
        CODEGEN("goto Label%d",$$);
        LABELGEN($1);
        create_symbol();
    }
casebody
    : CASE case_lit ':' {
        $$.key=$2;
        $$.label=label_cnt++;
        $$.isdefault=false;
        $$.next=NULL;
        LABELGEN($$.label);
        create_symbol();
    }
;
defaultbody
    : DEFAULT ':' {
        $$.label=label_cnt++;
        $$.isdefault=true;
        $$.next=NULL;
        LABELGEN($$.label);
        create_symbol();
    }
;
switchhalfblock
    : SWITCH lor_expr '{' newlines {
        $$.enter_label=label_cnt++;
        $$.exit_label=label_cnt++;
        $$.first=NULL;
        CODEGEN("goto Label%d\n",$$.enter_label);
    }
    | switchhalfblock casebody newlines '{' lines '}' newlines {
        struct case_node* newnode=casedup($2);
        newnode->next=$$.first;
        $$.first=newnode;
        CODEGEN("goto Label%d\n",$1.exit_label);
        dump_symbol();
    }
    | switchhalfblock defaultbody newlines '{' lines '}' newlines {
        struct case_node* newnode=casedup($2);
        newnode->next=$$.first;
        $$.first=newnode;
        CODEGEN("goto Label%d\n",$1.exit_label);
        dump_symbol();
    }
;
line
    : blockbody '{' lines '}' {
        dump_symbol();
    }
    | equation
    | VAR IDENT exprable_type dec_assign {
        insert_symbol($2,$3);
        if($4!=type_void){
            check_match("ASSIGN",$3,$4);
            mystore($2);
        }
    }
    | VAR IDENT STRING{
        insert_symbol($2,type_s);
        CODEGEN("ldc \"\"\n");
        mystore($2);
    }
    | VAR IDENT STRING '=' string_lit {
        insert_symbol($2,type_s);
        mystore($2);
    }
    | IDENT INC {
        unsigned char tp=myload($1);
        check_type_define("INC",tp,type_i|type_f);
        if(tp==type_f){
            CODEGEN("ldc 1.0\n");
            CODEGEN("fadd\n");
        }else{
            CODEGEN("iconst_1\n");
            CODEGEN("iadd\n");
        } 
        mystore($1);
    }
    | IDENT DEC {
        unsigned char tp=myload($1);
        check_type_define("DEC",tp,type_i|type_f);
        if(tp==type_f){
            CODEGEN("ldc 1.0\n");
            CODEGEN("fsub\n");
        }else{
            CODEGEN("iconst_1\n");
            CODEGEN("isub\n");
        } 
        mystore($1);
    }
    | PRINTLN '(' lor_expr ')' {
        println_post($3);
    }
    | PRINTLN '(' string_lit ')' {
        println_post($3);
    }
    | PRINT '(' lor_expr ')' {
        print_post($3);
    }
    | PRINT '(' string_lit ')' {
        print_post($3);
    }
    | ifbody newlines '{' lines '}' {
        LABELGEN($1);
        dump_symbol();
    }
    | ifblockelsebody newlines '{' lines '}' {
        LABELGEN($1);
        dump_symbol();
    }
    | forbody newlines '{' lines '}' {
        CODEGEN("goto Label%d\n",$1.again);
        LABELGEN($1.out);
        dump_symbol();
    }
    | switchhalfblock '}' {
        my_lookupswitch($1);
    }
    | RETURN lor_expr {
        switch($2){
        case type_i:
            CODEGEN("ireturn\n");
            break;
        case type_f:
            CODEGEN("freturn\n");
            break;
        case type_b:
            CODEGEN("breturn\n");
            break;
        }
        
    }
    | RETURN string_lit {
        CODEGEN("sreturn\n");
    }
    | RETURN {
        CODEGEN("return\n");
    }
    |
;
equation
    : IDENT '=' lor_expr {
        unsigned char tp=ident_type($1);
        check_match("ASSIGN",tp,$3);
        mystore($1);
    }
    | IDENT ADD_ASSIGN lor_expr {
        unsigned char tp=myload($1);
        check_match("ADD",tp,$3);
        CODEGEN("swap\n");
        if(tp==type_f){
            CODEGEN("fadd\n");
        }else{
            CODEGEN("iadd\n");
        } 
        mystore($1);
    }
    | IDENT SUB_ASSIGN lor_expr {
        unsigned char tp=myload($1);
        check_match("SUB",tp,$3);
        CODEGEN("swap\n");
        if(tp==type_f){
            CODEGEN("fsub\n");
        }else{
            CODEGEN("isub\n");
        } 
        mystore($1);
    }
    | IDENT MUL_ASSIGN lor_expr {
        unsigned char tp=myload($1);
        check_match("MUL",tp,$3);
        CODEGEN("swap\n");
        if(tp==type_f){
            CODEGEN("fmul\n");
        }else{
            CODEGEN("imul\n");
        } 
        mystore($1);
    }
    | IDENT QUO_ASSIGN lor_expr {
        unsigned char tp=myload($1);
        check_match("QUO",tp,$3);
        CODEGEN("swap\n");
        if(tp==type_f){
            CODEGEN("fdiv\n");
        }else{
            CODEGEN("idiv\n");
        } 
        mystore($1);
    }
    | IDENT REM_ASSIGN lor_expr {
        unsigned char tp=myload($1);
        check_type_define("REM",tp,type_i);
        check_type_define("REM",$3,type_i);
        CODEGEN("swap\n");
        CODEGEN("irem\n");
        mystore($1);
    }
    | IDENT '=' string_lit {
        unsigned char tp=ident_type($1);
        check_match("ASSIGN",tp,$3);
        mystore($1);
    }
    | lor_expr
;
lor_expr
    : lor_expr LOR land_expr {
        check_type_define("LOR",$1,type_b);
        check_type_define("LOR",$3,type_b);
        $$=type_b;
        CODEGEN("ior\n");
    }
    | land_expr
;
land_expr
    : land_expr LAND equ_expr {
        check_type_define("LAND",$1,type_b);
        check_type_define("LAND",$3,type_b);
        $$=type_b;
        CODEGEN("iand\n");
    }
    | equ_expr
;
equ_expr
    : equ_expr EQL cmp_expr {
        check_match("EQL",$1,$3);
        $$=type_b;
        if($1==type_f){
            my_fcmp("eq");
        }else{
            my_icmp("eq");
        }
    }
    | cmp_expr
;
cmp_expr
    : cmp_expr '>' expr {
        check_match("GTR",$1,$3);
        $$=type_b;
        if($1==type_f){
            my_fcmp("gt");
        }else{
            my_icmp("gt");
        }
    }
    | cmp_expr GEQ expr {
        check_match("GEQ",$1,$3);
        $$=type_b;
        if($1==type_f){
            my_fcmp("ge");
        }else{
            my_icmp("ge");
        }
    }
    | expr
;
expr
    : expr '+' term {
        $$=check_match("ADD",$1,$3);
        if($1==type_f){
            CODEGEN("fadd\n");
        }else{
            CODEGEN("iadd\n");
        }
    }
    | expr '-' term {
        $$=check_match("SUB",$1,$3);
        if($1==type_f){
            CODEGEN("fsub\n");
        }else{
            CODEGEN("isub\n");
        }
    }
    | term 
;
term
    : term '*' fac {
        $$=check_match("MUL",$1,$3);
        if($1==type_f){
            CODEGEN("fmul\n");
        }else{
            CODEGEN("imul\n");
        }
    }
    | term '/' fac {
        $$=check_match("QUO",$1,$3);
        if($1==type_f){
            CODEGEN("fdiv\n");
        }else{
            CODEGEN("idiv\n");
        }
    }
    | term '%' fac {
        check_type_define("REM",$1,type_i);
        check_type_define("REM",$3,type_i);
        $$=type_i;
        CODEGEN("irem\n");
    }
    | fac
;
fac 
    : '+' fac {
        $$=check_type_define("POS",$2,type_i|type_f)?$2:type_error;
    }
    | '-' fac {
        $$=check_type_define("NEG",$2,type_i|type_f)?$2:type_error;
        if($2==type_f){
            CODEGEN("fneg\n");
        }else{
            CODEGEN("ineg\n");
        }
    }
    | '!' fac {
        $$=check_type_define("NOT",$2,type_b)?type_b:type_error;
        CODEGEN("iconst_1\n");
        CODEGEN("ixor\n");
    }
    | '(' lor_expr ')' {
        $$=$2;
    }
    | FLOAT '(' lor_expr ')' {
        check_type_define("i2f",$3,type_i);
        CODEGEN("i2f\n");
        $$=type_f;
    }
    | INT '(' lor_expr ')' {
        check_type_define("f2i",$3,type_f);
        CODEGEN("f2i\n");
        $$=type_i;
    }
    | IDENT '(' parastart ')' {
        int i=func_find($1);
        if(i!=-1){
            $$=func_table[i].type;
            CODEGEN("invokestatic Main/%s(%s)%c\n",$1,func_table[i].func_sig,get_type($$));
        }else{
            printf("error:%d: undefined: %s\n",reduce_line,$1);
            g_has_error=true;
        }
    }
    | ident {
        $$=$1;
    }
    | int_lit {
        $$=$1;
    }
    | float_lit {
        $$=$1;
    }
    | bool_lit {
        $$=$1;
    }
;
case_lit
    : INT_LIT {
        $$=$1;
    }
    | '-' INT_LIT {
        $$=-$2;
    }
;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", argv[1]);
        exit(1);
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    

    /* Symbol table init */
    // Add your code

    yylineno = 0;
    yyparse();

    /* Symbol table dump */
    // Add your code

	printf("Total lines: %d\n", reduce_line-1);
    fclose(fout);
    fclose(yyin);

    if (g_has_error) {
        remove(bytecode_filename);
    }
    yylex_destroy();
    return 0;
}