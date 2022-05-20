#ifndef COMPILER_HW_COMMON_H
#define COMPILER_HW_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Add what you need */

struct forloop_node{
    int again;
    int out;
};
struct case_node{
    int label;
    int key;
    bool isdefault;
    struct case_node* next;
};

struct switch_node{
    int exit_label;
    int enter_label;
    struct case_node* first;
};


extern int scope_level;
extern int yylineno;
extern bool g_has_error;
extern int reduce_line;
#endif /* COMPILER_HW_COMMON_H */