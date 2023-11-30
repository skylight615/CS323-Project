#include "funcTable.h"
#include "stdlib.h"
#include "string.h"

func *func_head, *func_tail;

// add a var into linkedlist
void new_func(char *name, char *rtype, char *va_type[], int va_num){
    func *temp = (func*)malloc(sizeof(func));
    temp->name = (char*)malloc(sizeof(char)*strlen(name));
    temp->rtype = (char*)malloc(sizeof(char)*strlen(rtype));
    temp->va_num = va_num;
    strcpy(temp->name, name);
    strcpy(temp->rtype, rtype);
    int count = 0;
    for (int i = va_num-1; i >= 0; i--){
        temp->va_type[count] = (char*)malloc(sizeof(char)*strlen(va_type[i]));
        strcpy(temp->va_type[count++], va_type[i]);
    }
    func_tail->before->next = temp;
    temp->before = func_tail->before;
    temp->next = func_tail;
    func_tail->before = temp;
}

// find the variable if exist
func* find_func(char *name, char *va_type[], int va_num){
    func *temp = func_head->next;
    while (temp != func_tail)
    {
        if (!strcmp(temp->name, name) && va_num == temp->va_num){
            int para = 1;
            for (int i = 0; i < va_num; i++){
                para = strcmp(va_type[i], temp->va_type[i]) & para;
                if (!para){
                    break;
                }
            }
            if (para){
                return temp;
            }
        }
        temp = temp->next;
    }
    return NULL;
}