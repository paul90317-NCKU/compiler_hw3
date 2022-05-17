#ifndef __MY_SYMBOL_TABLE_H
#define __MY_SYMBOL_TABLE_H

#include "compiler_hw_common.h"
#include "myType.h"

struct symbol_node symbol_table[1000];
int scope_level=-1;//next is 0
int scope_level_stack_init[1000]={0};
int stack_back=0;
int next_addr=0;
struct func_node func_table[1000];
int func_back=0;

int symbol_find(char* id){
    for(int i=stack_back-1;i>=0;--i){
        if(strcmp(id,symbol_table[i].name)==0)
            return i;
    }
    return -1;
}
unsigned char ident_type(char* id){
    int i=symbol_find(id);
    if(i==-1)return type_error;
    return symbol_table[i].type;
}
int func_find(char* id){
    for(int i=func_back-1;i>=0;--i){
        if(strcmp(id,func_table[i].name)==0)
            return i;
    }
    return -1;
}
int symbol_find_in_block(char* id){
    for(int i=stack_back-1;i>=scope_level_stack_init[scope_level];--i){
        if(strcmp(id,symbol_table[i].name)==0)
            return i;
    }
    return -1;
}

void create_symbol() {
    scope_level_stack_init[++scope_level]=stack_back;
}
void dump_symbol() {
    stack_back=scope_level_stack_init[scope_level--];
}

void insert_symbol(char * ident, unsigned char data_type) {
    int prev=symbol_find_in_block(ident);
    if(prev!=-1){
        printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,ident,symbol_table[prev].lineno);
        g_has_error=true;
    }
    symbol_table[stack_back].lineno=yylineno;
    symbol_table[stack_back].type=data_type;
    symbol_table[stack_back].name=ident;
    symbol_table[stack_back].addr=next_addr++;
    stack_back++;
}

void insert_func(char * ident, char* sig, unsigned char ret_type) {
    func_table[func_back].type=ret_type;
    func_table[func_back].name=ident;
    func_table[func_back].func_sig=sig;
    func_table[func_back].lineno=yylineno;
    func_back++;
}

#endif