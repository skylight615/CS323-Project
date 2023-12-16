#include "interCode.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

iCode* head;
iCode* tail;

void init(){
    head = (iCode*)malloc(sizeof(iCode));
    tail = (iCode*)malloc(sizeof(iCode));
    head->next = tail;
    tail->before = head;
}

void print_code(){
    iCode* ptr = head->next;
    while (ptr != tail)
    {
        for (int i = 0; i < ptr->com_num; i++){
            printf("%s ", ptr->sentence[i]);
        }
        printf("\n");
        ptr = ptr->next;
    }
}

iCode* new_code(int num){
    iCode* node = (iCode*)malloc(sizeof(iCode));
    node->com_num = num;
    node->used = 0;
    node->sentence = (char**)malloc(sizeof(char*)*num);
    return node;
}

void link2list(iCode* tail, iCode* node){
    tail->before->next = node;
    node->before = tail->before;
    node->next = tail;
    tail->before = node;
}

void append(iCode* node,char* unit){
    node->sentence[node->used] = (char*)malloc(sizeof(char)*strlen(unit));
    strcpy(node->sentence[node->used], unit);
    node->used+=1;
}