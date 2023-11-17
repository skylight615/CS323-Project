#include "funcTable.h"
#include "stdlib.h"
#include "string.h"

// add a var into linkedlist
void new_func(char *name, char *rtype, char *va_type[], int va_num){
    func *temp = (func*)malloc(sizeof(func));
    temp->name = (char*)malloc(sizeof(char)*strlen(name));
    temp->rtype = (char*)malloc(sizeof(char)*strlen(rtype));
    temp->va_num = va_num;
    strcpy(temp->name, name);
    strcpy(temp->rtype, rtype);
    for (int i = 0; i < va_num; i++){
        strcpy(temp->va_type[i], va_type[i]);
    }
    func_tail->before->next = temp;
    temp->before = func_tail->before->next;
    temp->next = func_tail;
    func_tail->before = temp;
}

// find the variable if exist
int find_func(char *name, char *rtype, char *va_type[], int va_num){
    func *temp = func_head->next;
    while (temp != func_tail)
    {
        if (!strcmp(temp->name, name) && !strcmp(temp->rtype, rtype) && va_num == temp->va_num){
            int para = 1;
            for (int i = 0; i < va_num; i++){
                para = strcmp(va_type[i], temp->va_type[i]) & para;
                if (!para){
                    break;
                }
            }
            if (para){
                return 1;
            }
        }
        temp = temp->next;
    }
    return 0;
}