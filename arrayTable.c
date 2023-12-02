#include "arrayTable.h"
#include "syntax.tab.h"
#include "string.h"
#include "stdlib.h"

extern int LCnum;

array *array_head, *array_tail;

// add a var into linkedlist
void new_array(char *name, char *type, int* size, char* func){
    array *next = (array *)malloc(sizeof(array));
    next->name = (char*)malloc(sizeof(char)*strlen(name));
    next->type = (char*)malloc(sizeof(char)*strlen(type));
    next->func = (char*)malloc(sizeof(char)*strlen(func));
    strcpy(next->func, func);
    strcpy(next->name, name);
    strcpy(next->type, type);
    next->dm = *size;
    for (int i = 0; i < next->dm; i++){
        next->size[i] = *(size+i+1);
    }
    next->level = LCnum;
    array_tail->before->next = next;
    next->before = array_tail->before;
    next->next = array_tail;
    array_tail->before = next;
}

// find the variable if exist
array* find_array(char *name, char* current_func){
    array *temp = array_head->next;
    while (temp != array_tail)
    {
        if (!strcmp(temp->name, name) && temp->level == LCnum && !strcmp(current_func, temp->func)){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}