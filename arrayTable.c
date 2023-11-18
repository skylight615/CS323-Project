#include "arrayTable.h"
#include "syntax.tab.h"
#include "string.h"
#include "stdlib.h"

extern int LCnum;

// add a var into linkedlist
void new_array(char *name, char *type, int size){
    array *next = (array *)malloc(sizeof(array));
    next->name = (char*)malloc(sizeof(char)*strlen(name));
    next->type = (char*)malloc(sizeof(char)*strlen(type));
    strcpy(next->name, name);
    strcpy(next->type, type);
    next->size = size;
    next->level = LCnum;
    array_tail->before->next = next;
    next->before = array_tail->before->next;
    next->next = array_tail;
    array_tail->before = next;
}

// find the variable if exist
int find_array(char *name, char *type){
    array *temp = array_head->next;
    while (temp != array_tail)
    {
        if (!strcmp(temp->name, name) && !strcmp(temp->type, type) && temp->level == LCnum){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}