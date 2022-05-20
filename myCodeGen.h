#ifndef __MY_CODE_GEN_H
#define __MY_CODE_GEN_H
#include "compiler_hw_common.h"
#include "myType.h"
#include "mySymbolTable.h"

static int g_indent_cnt = 0;
static FILE *fout = NULL;

#define CODEGEN(...) \
    do { \
        for (int i = 0; i < g_indent_cnt; i++) { \
            fprintf(fout, "\t"); \
        } \
        fprintf(fout, __VA_ARGS__); \
    } while (0)

static int label_cnt=0;
void LABELGEN(int l){
    g_indent_cnt--;
    CODEGEN("Label%d:\n",l);
    g_indent_cnt++;
}

void code_begin(){
    CODEGEN(".source hw3.j\n");
    CODEGEN(".class public Main\n");
    CODEGEN(".super java/lang/Object\n");
}

void method_begin(char* name,char *sigs,unsigned char rtype){
    CODEGEN(".method public static %s(%s)%c\n",name,sigs,get_type(rtype));
    CODEGEN(".limit stack 100\n");
    CODEGEN(".limit locals 100\n");
    next_addr=0;
    insert_func(name,sigs,rtype);
    g_indent_cnt++;
}
void main_method_begin(){
    CODEGEN(".method public static main([Ljava/lang/String;)V\n");
    CODEGEN(".limit stack 100\n");
    CODEGEN(".limit locals 100\n");
    next_addr=1;
    insert_func("main","",type_void);
    g_indent_cnt++;
}
void method_end(){
    CODEGEN("return\n");
    g_indent_cnt--;
    CODEGEN(".end method\n");
}
void println_post(unsigned char ptype){
    int l1,l2;
    switch(ptype){
    case type_b:
        l1=label_cnt++;
        l2=label_cnt++;
        CODEGEN("ifeq Label%d\n",l1);
        CODEGEN("ldc \"true\"\n");
        CODEGEN("goto Label%d\n",l2);
        LABELGEN(l1);
        CODEGEN("ldc \"false\"\n");
        LABELGEN(l2);
    case type_s:
        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        CODEGEN("swap\n");
        CODEGEN("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
        break;
    default:
        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        CODEGEN("swap\n");
        CODEGEN("invokevirtual java/io/PrintStream/println(%c)V\n",get_type(ptype));
    }
}
void print_post(unsigned char ptype){
    int l1,l2;
    switch(ptype){
    case type_b:
        l1=label_cnt++;
        l2=label_cnt++;
        CODEGEN("ifeq Label%d\n",l1);
        CODEGEN("ldc \"true\"\n");
        CODEGEN("goto Label%d\n",l2);
        LABELGEN(l1);
        CODEGEN("ldc \"false\"\n");
        LABELGEN(l2);
    case type_s:
        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        CODEGEN("swap\n");
        CODEGEN("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        break;
    default:
        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        CODEGEN("swap\n");
        CODEGEN("invokevirtual java/io/PrintStream/print(%c)V\n",get_type(ptype));
    }
}

unsigned char myload(char* name){
    int ad=symbol_find(name);
    if(ad==-1){
        printf("error:%d: undefined: %s\n",reduce_line,name);
        return type_error;
    }
    struct symbol_node* s=symbol_table+ad;
    switch(s->type){
    case type_f:
        CODEGEN("fload %d\n",s->addr);
        break;
    case type_i:
    case type_b:
        CODEGEN("iload %d\n",s->addr);
        break;
    case type_s:
        CODEGEN("aload %d\n",s->addr);
        break;
    }
    return s->type;
}
void mystore(char* name){
    int ad=symbol_find(name);
    if(ad==-1){
        printf("error:%d: undefined: %s\n",reduce_line,name);
        return;
    }
    struct symbol_node* s=symbol_table+ad;
    switch(s->type){
    case type_f:
        CODEGEN("fstore %d\n",s->addr);
        break;
    case type_i:
    case type_b:
        CODEGEN("istore %d\n",s->addr);
        break;
    case type_s:
        CODEGEN("astore %d\n",s->addr);
        break;
    }
}

void my_icmp(char* op){
    int l1=label_cnt++;
    int l2=label_cnt++;
    CODEGEN("isub\n");
    CODEGEN("if%s Label%d\n",op,l1);
    CODEGEN("iconst_0\n");
    CODEGEN("goto Label%d\n",l2);
    LABELGEN(l1);
    CODEGEN("iconst_1\n");
    LABELGEN(l2);
}
void my_fcmp(char* op){
    int l1=label_cnt++;
    int l2=label_cnt++;
    CODEGEN("fcmpl\n");
    CODEGEN("if%s Label%d\n",op,l1);
    CODEGEN("iconst_0\n");
    CODEGEN("goto Label%d\n",l2);
    LABELGEN(l1);
    CODEGEN("iconst_1\n");
    LABELGEN(l2);
}

int if_begin(){
    int l1=label_cnt++;
    CODEGEN("ifeq Label%d\n",l1);
    return l1;
}
#endif