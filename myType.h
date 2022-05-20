#ifndef MY_TYPE_H__
#define MY_TYPE_H__

#include "compiler_hw_common.h"

#define type_b 1
#define type_i 2
#define type_f 4
#define type_s 8
#define type_error 16
#define type_void 32

static char buf[100];
void get_type_tobuf(unsigned char type){
    switch(type){
    case type_f:
        strcpy(buf,"float32");
        break;
    case type_i:
        strcpy(buf,"int32");
        break;
    case type_s:
        strcpy(buf,"string");
        break;
    case type_b:
        strcpy(buf,"bool");
        break;
    case type_void:
        strcpy(buf,"void");
        break;
    default:
        strcpy(buf,"ERROR");
    }
}

char get_type(unsigned char type){
    switch(type){
    case type_f:
        return 'F';
    case type_i:
        return 'I';
    case type_s:
        return 'S';
    case type_b:
        return 'B';
    case type_void:
        return 'V';
    default:
        return 'E';
    }
}


unsigned check_match(char *op,unsigned a,unsigned b){
    if(a==b)return a;
    get_type_tobuf(a);
    printf("error:%d: invalid operation: %s (mismatched types %s ",reduce_line,op,buf);
    g_has_error=true;
    get_type_tobuf(b);
    printf("and %s)\n",buf);
    return type_error;
}

void check_bool_condition(unsigned char a){
    if(a==type_b)return;
    get_type_tobuf(a);
    printf("error:%d: non-bool (type %s) used as for condition\n",reduce_line,buf);
    g_has_error=true;
}
bool check_type_define(char* op,unsigned char yourtype,unsigned char mask){
    if(yourtype&mask)return true;
    get_type_tobuf(yourtype);
    printf("error:%d: invalid operation: (operator %s not defined on %s)\n",reduce_line,op,buf);
    g_has_error=true;
    return false;
}

#endif