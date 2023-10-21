#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "syntax.tab.h"

struct Node *createLeaf(char* type,char* value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->n_cld = 0;
    strcpy(node->type, type);
    if (strcmp(type,"ID")==0 || strcmp(type,"FLOAT") || strcmp(type,"INT") || strcmp(type,"CHAR")){
        node->value = (char*)malloc(sizeof(char)*strlen(value));
        strcpy(node->value, value);
    } else {
        node->value = NULL;
    }
    return node;
}

/*构造抽象语法树,变长参数，name:语法单元名字；num:变长参数中语法结点个数*/
struct Node *createNode(char* type,int num, struct Node* list[]){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->n_cld = num;
    strcpy(node->type, type);
    node->value = NULL;
    for (int i = 0; i < num; i++){
        node->clds[i] = list[i];
    }
    return node;
}

/*遍历抽象语法树，level为树的层数*/
void dfs(struct Node* root,int level){
    int i;
	if(root !=NULL)
	{
		for(i=0; i<4*level; i++)
			printf("    ");
		
		if(root->value==NULL)
			printf("%s\n", root->type);
		else 
			printf("%s: %s\n", root->type, root->value);
		
		for (i=0; i<root->n_cld; i++) {  
			dfs((root->clds)[i], level+1);
		}
    }
}
