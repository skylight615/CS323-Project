#include "varTable.h"
#include "structTable.h"
#include "syntax.tab.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern int LCnum;

// add a var into linkedlist
void new_var(char* type, char* name){
    var *next = (var *)malloc(sizeof(var));
    next->name = (char*)malloc(sizeof(char)*strlen(name));
    next->type = (char*)malloc(sizeof(char)*strlen(type));
    strcpy(next->name, name);
    strcpy(next->type, type);
    next->level = LCnum;
    var_tail->before->next = next;
    next->before = var_tail->before->next;
    next->next = var_tail;
    var_tail->before = next;
}

// find the variable if exist
var* find_var(char* type, char* name){
    var* temp = var_head->next;
    while (temp != var_tail)
    {
        // equal
        if (!strcmp(temp->name, name) && !strcmp(temp->type, type) && temp->level <= LCnum){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}