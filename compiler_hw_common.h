#ifndef COMPILER_HW_COMMON_H
#define COMPILER_HW_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Add what you need */

#define type_b 1
#define type_i 2
#define type_f 4
#define type_s 8
#define type_error 16
#define type_void 32

struct symbol_node{
    char* name;
    unsigned char type;
    int lineno;
    int addr;
};
struct func_node{
    char* name;
    unsigned char type;
    int lineno;
    char *func_sig;
};
struct forloop_node{
    int again;
    int out;
};

extern struct symbol_node symbol_table[1000];
extern int scope_level_stack_init[1000];
extern int stack_back;
extern struct func_node func_table[1000];
extern int func_back;

extern int scope_level;
extern int yylineno;
extern bool g_has_error;
#endif /* COMPILER_HW_COMMON_H */