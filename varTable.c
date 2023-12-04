#include "varTable.h"
#include "structTable.h"
#include "syntax.tab.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern int LCnum;
extern int func_num;
extern int struct_num;
var *var_head, *var_tail;

// add a var into linkedlist
void new_var(char* type, char* name){
    var *next = (var *)malloc(sizeof(var));
    next->name = (char*)malloc(sizeof(char)*strlen(name));
    next->type = (char*)malloc(sizeof(char)*strlen(type));
    strcpy(next->name, name);
    strcpy(next->type, type);
    next->level = LCnum;
    next->from_func=func_num;
    next->from_struct=struct_num;
    var_tail->before->next = next;
    next->before = var_tail->before;
    next->next = var_tail;
    var_tail->before = next;

}

// find the variable if exist
var* find_var(char* name){
    var* temp = var_head->next;
    while (temp != var_tail)
    {
        // equal
        if (!strcmp(temp->name, name) && temp->level <= LCnum && temp->from_func==func_num){
            return temp;
        }
        temp = temp->next;
    }
    var* res=NULL;
    return NULL;
}

var* find_var_struct(char* name,int struct_num){
    var* temp = var_head->next;
    while (temp != var_tail)
    {
        // equal
        if (!strcmp(temp->name, name) && temp->level <= LCnum && temp->from_struct==struct_num ){
            return temp;
        }
        temp = temp->next;
    }
    var* res=NULL;
    return NULL;
}