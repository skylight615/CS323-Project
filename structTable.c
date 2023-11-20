#include "structTable.h"
#include "string.h"
#include "stdlib.h"

// add a struct into linkedlist
void new_struct(char *name, char *type[], int typeNum){
    Struct* temp = (Struct*)malloc(sizeof(Struct));
    temp->name = (char*)malloc(sizeof(char)*strlen(name));
    strcpy(temp->name, name);
    temp->typeNum = typeNum;
    for (int i = 0; i < typeNum; i++){
        temp->type[i] = (char*)malloc(sizeof(char)*strlen(type[i]));
        strcpy(temp->type[i], type[i]);
    }
    struct_tail->before->next = temp;
    temp->before = struct_tail->before->next;
    temp->next = struct_tail;
    struct_tail->before = temp;
}

//this function is used when program defines a struct variable eg. struct book a;. And used to judge whether the book type exists;
Struct* find_struct(char *name){
    Struct* temp = struct_head->next;
    while (temp != struct_tail)
    {
        if (!strcmp(temp->name, name)){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

/*this function works when the program is defining a new struct type, eg. struct book2{int a; float b;}. 
 *And it can judge whether there is a same structual type.
 *two situations mean the new type is conflict:
 *1. the name has existed
 *2. the struct types is same with another stuct; 
 *If the return is not null, it means there is error;
*/
Struct* structual_equal(char *name, char *type[], int typeNum){
    Struct* temp = struct_head->next;
    while (temp != struct_tail)
    {
        if (!strcmp(temp->name, name)){
            return temp;
        }
        if (temp->typeNum == typeNum){
            int equal = 1;
            for (int i = 0; i < typeNum; i++){
                equal = equal ^ strcmp(temp->type[i], type[i]);
                if (!equal){
                    break;
                }
            }
            if (equal) {
                return temp;
            }
        }
        temp = temp->next;
    }
    return NULL;
}