#include "structTable.h"
#include "string.h"
#include "stdlib.h"

// add a struct into linkedlist
void new_struct(char *name){
    Struct* temp = (Struct*)malloc(sizeof(Struct));
    temp->name = (char*)malloc(sizeof(char)*strlen(name));
    strcpy(temp->name, name);
    struct_tail->before->next = temp;
    temp->before = struct_tail->before->next;
    temp->next = struct_tail;
    struct_tail->before = temp;
}

// find the variable if exist
int find_struct(char *name){
    Struct* temp = struct_head->next;
    while (temp != struct_tail)
    {
        if (!strcmp(temp->name, name)){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}