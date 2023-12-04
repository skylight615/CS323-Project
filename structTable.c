#include "structTable.h"
#include "string.h"
#include "stdlib.h"
#include <stdio.h>

Struct *struct_head, *struct_tail;
int struct_num=0;;
extern int struct_num;
// add a struct into linkedlist
void new_struct(char *name, char *type[], int typeNum){
    Struct* temp = (Struct*)malloc(sizeof(Struct));
    temp->name = (char*)malloc(sizeof(char)*strlen(name));
    strcpy(temp->name, name);
    temp->typeNum = typeNum;
    temp->structnum=struct_num;
    for (int i = 0; i < typeNum; i++){
        temp->type[i] = (char*)malloc(sizeof(char)*strlen(type[i]));
        strcpy(temp->type[i], type[i]);
    }
    struct_tail->before->next = temp;
    temp->before = struct_tail->before;
    temp->next = struct_tail;
    struct_tail->before = temp;
    struct_num++;
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
int structual_equal2(Struct *a, Struct *b){
    if(a->typeNum==b->typeNum ){
        int aint=0;int afloat=0;int achar=0;
        for(int i=0;i<a->typeNum;i++){
            if(!strcmp(a->type[i], "int")){
                aint++;
            }else if(!strcmp(a->type[i], "float")){
                afloat++;
            }else{
                achar++;
            }
        }
        int bint=0;int bfloat=0; int bchar=0;
        for(int i=0;i<b->typeNum;i++){
            if(!strcmp(b->type[i], "int")){
                bint++;
            }else if(!strcmp(b->type[i], "float")){
                bfloat++;
            }else{
                bchar++;
            }
        }
        if(aint==bint&& afloat==bfloat&& achar==bchar){
            return 1;
        }
    }
    return 0;
}