#ifndef MY_SWITCH_H__
#define MY_SWITCH_H__

#include "compiler_hw_common.h"

#include "myCodeGen.h"

struct case_node* casedup(struct case_node src){
    struct case_node* ret=malloc(sizeof(struct case_node));
    memcpy(ret,&src,sizeof(struct case_node));
    return ret;
}

void my_lookupswitch(struct switch_node swi){
    LABELGEN(swi.enter_label);
    g_indent_cnt--;
    CODEGEN("lookupswitch\n");
    g_indent_cnt++;
    for(struct case_node* now=swi.first;now!=NULL;now=now->next){
        if(!now->isdefault){
            CODEGEN("%d: Label%d\n",now->key,now->label);
        }
    }
    for(struct case_node* now=swi.first;now!=NULL;now=now->next){
        if(now->isdefault){
            CODEGEN("default: Label%d\n",now->label);
        }
    }
    LABELGEN(swi.exit_label);
}



#endif