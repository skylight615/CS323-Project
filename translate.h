#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "tree.h"
#include "interCode.h"

char* new_place();
char* new_label();
void translate_Program(struct Node* node);
void translate_ExtDefList(struct Node* node);
void translate_ExtDef(struct Node* node);
// void translate_ExtDecList(struct Node* node);
// void translate_Specifier(struct Node* node);
// void translate_StructSpecifier();
void translate_VarDec(struct Node* node);
void translate_FunDec(struct Node* node);
void translate_VarList(struct Node* node);
void translate_ParamDec(struct Node* node);
void translate_CompSt(struct Node* node);
void translate_StmtList(struct Node* node);
void translate_Stmt(struct Node* node);
void translate_DefList(struct Node* node);
void translate_Def(struct Node* node);
void translate_DecList(struct Node* node);
void translate_Dec(struct Node* node);
void translate_Exp(struct Node* node, char* var);
void translate_cond_Exp(struct Node* node, char* lbt, char* lbf);
void translate_Args(struct Node* node);

#endif