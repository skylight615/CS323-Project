#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "syntax.tab.h"


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

/*构造抽象语法树,变长参数，name:语法单元名字；num:变长参数中语法结点个数*/
struct Node *createNode(char* type,int num, struct Node* list[]){
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
