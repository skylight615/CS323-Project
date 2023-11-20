#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "syntax.tab.h"
#include "arrayTable.h"
#include "varTable.h"
#include "funcTable.h"
#include "structTable.h"


struct Node *createLeaf(char* type,char* value){
    extern int yylineno;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->n_cld = 0;
    node->type = (char*)malloc(sizeof(char)*strlen(type));
    strcpy(node->type, type);
    node->line = yylineno;
    if (strcmp(type,"ID")==0 || strcmp(type,"FLOAT")==0 || strcmp(type,"INT")==0 || 
        strcmp(type,"CHAR")==0 || strcmp(type,"TYPE")==0 ||strcmp(type,"FILEIN")==0){
        node->value = (char*)malloc(sizeof(char)*strlen(value));
        strcpy(node->value, value);
    }else {
        node->value = "SIG";
    }
    return node;
}



/*构造抽象语法树,变长参数，name:语法单元名字；num:变长参数中语法结点个数
* attr represents the type of value(int(1), float(2) or char(3))
*/
struct Node *createNode(char* type, int num, struct Node* list[]){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->n_cld = num;
    node->type = (char*)malloc(sizeof(char)*strlen(type));
    strcpy(node->type, type);
    node->line = RAND_MAX;
    node->value = NULL;
    for (int i = 0; i < num; i++){
        node->clds[i] = list[i];
        node->line = (node->line > list[i]->line) ? list[i]->line : node->line;
    }
    return node;
}

char* findToken(struct Node* root, char* type){
	if(root == NULL){
        return NULL;
    }
    char *res;
    if (strcmp(root->type,type)==0) {
        return root->value;
    } else {
        for (int i = 0; i < root->n_cld; i++){
            res = findToken(root->clds[i], type);
            if (res != NULL){
                break;
            }
        }
    }
    return res;
}

int isArray(struct Node* root){
    if(root == NULL){
        return 0;
    }
    int res = 0;
    char* lb = "LB";
    if (strcmp(root->type, lb)==0) {
        return 1;
    } else {
        for (int i = 0; i < root->n_cld; i++){
            res = isArray(root->clds[i]);
            if (res){
                break;
            }
        }
    }
    return res;
}

/*遍历抽象语法树，level为树的层数*/
void dfs(struct Node* root,int level){
    int i;
	if(root !=NULL)
	{
        if (strcmp(root->type,"Empty")!=0) {
            for(i=0; i<level; i++)
			    printf("  ");
            if(root->value==NULL)
                printf("%s (%d)\n", root->type, root->line);
            else if(strcmp(root->value,"SIG")==0) printf("%s\n", root->type);
            else 
                printf("%s: %s\n", root->type, root->value);
            for (i=0; i<root->n_cld; i++) {  
                dfs((root->clds)[i], level+1);
            }
        }
    }
}

void debug(){
    printf("function table: \n");
    func* temp = func_head->next;
    while (temp != func_tail)
    {
        printf("%s, %s, %d", temp->name, temp->rtype, temp->va_num);
        for (int i = 0; i < temp->va_num; i++){
            printf(" %s,", temp->va_type[i]);
        }
        printf("\n");
        temp = temp->next;
    }
    printf("\n\n");
    printf("variable table: \n");
    var* var_temp = var_head->next;
    while (var_temp != var_tail)
    {
        printf("%s %s %d\n", var_temp->type, var_temp->name, var_temp->level);
        var_temp = var_temp->next;
    }
    printf("\n\n");
    printf("array table: \n");
    array* array_temp = array_head->next;
    while (array_temp != array_tail)
    {
        printf("%s %s %d %d\n", array_temp->type, array_temp->name, array_temp->size, array_temp->level);
        array_temp = array_temp->next;
    }
    printf("\n\n");
    printf("struct table: \n");
    Struct* s_temp = struct_head->next;
    while (s_temp != struct_tail)
    {
        printf("%s ", s_temp->name);
        for (int i = 0; i < s_temp->typeNum; i++){
            printf("%s ", s_temp->type[i]);
        }
        printf("\n");
        s_temp = s_temp->next;
    }
}