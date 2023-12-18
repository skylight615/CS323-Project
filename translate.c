#include "translate.h"
#include "interCode.h"
#include "tree.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

extern iCode* head;
extern iCode* tail;
int var_count = 0;
int lb_count = 0;

char* new_place(){
    char* num = (char*)malloc(sizeof(char) * 10);
    sprintf(num, "%d", var_count++);
    char* place = (char*)malloc(sizeof(char) * (strlen(num) + 1));
    place[0] = 't';
    strcpy(place+1, num);
    free(num);
    return place;
}

char* new_label(){
    char* num = (char*)malloc(sizeof(char) * 10);
    sprintf(num, "%d", lb_count++);
    char* label = (char*)malloc(sizeof(char) * (strlen(num) + 1));
    strcpy(label, "label");
    strcpy(label+5, num);
    free(num);
    return label;
}

void translate_Program(struct Node* node){
    init();
    translate_ExtDefList(node->clds[0]);
    print_code();
}

void translate_ExtDefList(struct Node* node){
    printf("translate_ExtDefList\n");
    translate_ExtDef(node->clds[0]);
    if (strcmp(node->clds[1]->type, "Empty")){
        translate_ExtDefList(node->clds[1]);
    }
}

void translate_ExtDef(struct Node* node){
    printf("translate_ExtDef\n");
    if (!strcmp(node->clds[1]->type, "FunDec")){
        translate_FunDec(node->clds[1]);
        translate_CompSt(node->clds[2]);
    }
}

// void translate_ExtDecList(struct Node* node){}
// void translate_Specifier(struct Node* node){}
// void translate_StructSpecifier();
void translate_VarDec(struct Node* node){
    if (node->n_cld == 1){
        iCode* code = new_code(2);
        append(code, "PARAM");
        append(code, node->clds[0]->value);
        link2list(tail, code);
    }
}

void translate_FunDec(struct Node* node){
    printf("translate_FunDec\n");
    // FunDec = ID LP RP
    iCode* code = new_code(3);
    append(code, "FUNCTION");
    append(code, node->clds[0]->value);
    append(code, ":");
    link2list(tail, code);
    // FunDec = ID LP VarList RP
    if (node->n_cld == 4){
        translate_VarList(node->clds[2]);
    }
}

void translate_VarList(struct Node* node){
    printf("translate_VarList\n");
    translate_ParamDec(node->clds[0]);
    if (node->n_cld == 3){
        translate_VarList(node->clds[2]);
    }
}

void translate_ParamDec(struct Node* node){
    printf("translate_ParamDec\n");
    translate_VarDec(node->clds[1]);
}

void translate_CompSt(struct Node* node){
    printf("translate_CompSt\n");
    translate_StmtList(node->clds[2]);
}

void translate_StmtList(struct Node* node){
    printf("translate_StmtList\n");
    translate_Stmt(node->clds[0]);
    if (node->n_cld == 2 && strcmp(node->clds[1]->type, "Empty")){
        translate_StmtList(node->clds[1]);
    }
}

void translate_Stmt(struct Node* node){
    printf("translate_Stmt\n");
    if (node->n_cld == 1){
        //CompSt
        translate_CompSt(node->clds[0]);
    } else if (node->n_cld == 2){
        //Exp SEMI
        char* var = new_place();
        translate_Exp(node->clds[0], var);
    } else if (node->n_cld == 3){
        //RETURN Exp SEMI
        char* var = new_place();
        translate_Exp(node->clds[1], var);
        iCode* r = new_code(2);
        append(r, "RETURN");
        append(r, var);
        link2list(tail, r);
    } else if (node->n_cld == 5){
        char* lb1 = new_label();
        char* lb2 = new_label();
        //IF LP Exp RP Stmt or WHILE LP Exp RP Stmt
        if (!strcmp(node->clds[0]->type, "IF")){
            translate_cond_Exp(node->clds[2], lb1, lb2);
            iCode* code1 = new_code(3);
            append(code1, "LABEL");
            append(code1, lb1);
            append(code1, ":");
            link2list(tail, code1);
            translate_Stmt(node->clds[4]);
            iCode* code2 = new_code(3);
            append(code2, "LABEL");
            append(code2, lb2);
            append(code2, ":");
            link2list(tail, code2);
        } else {
            char* lb3 = new_label();
            iCode* code1 = new_code(3);
            append(code1, "LABEL");
            append(code1, lb1);
            append(code1, ":");
            link2list(tail, code1);
            translate_cond_Exp(node->clds[2], lb2, lb3);
            iCode* code2 = new_code(3);
            append(code2, "LABEL");
            append(code2, lb2);
            append(code2, ":");
            link2list(tail, code2);
            translate_Stmt(node->clds[4]);
            iCode* code3 = new_code(2);
            append(code3, "GOTO");
            append(code3, lb1);
            link2list(tail, code3);
            iCode* code4 = new_code(3);
            append(code4, "LABEL");
            append(code4, lb3);
            append(code4, ":");
            link2list(tail, code4);
        }
    } else {
        //IF LP Exp RP Stmt ELSE Stmt
        char* lb1 = new_label();
        char* lb2 = new_label();
        char* lb3 = new_label();
        translate_cond_Exp(node->clds[2], lb1, lb2);
        iCode* code1 = new_code(3);
        append(code1, "LABEL");
        append(code1, lb1);
        append(code1, ":");
        link2list(tail, code1);
        translate_Stmt(node->clds[4]);
        iCode* code2 = new_code(2);
        append(code2, "GOTO");
        append(code2, lb3);
        link2list(tail, code2);
        iCode* code3 = new_code(3);
        append(code3, "LABEL");
        append(code3, lb2);
        append(code3, ":");
        link2list(tail, code3);
        translate_Stmt(node->clds[6]);
        iCode* code4 = new_code(3);
        append(code4, "LABEL");
        append(code4, lb3);
        append(code4, ":");
        link2list(tail, code4);
    }
}

// void translate_DefList(struct Node* node){}
// void translate_Def(struct Node* node){}
// void translate_DecList(struct Node* node){}
// void translate_Dec(struct Node* node){}

void translate_Exp(struct Node* node, char* var){
    printf("translate_Exp\n");
    if (node->n_cld == 1){
        // INT or ID
        if (!strcmp("INT", node->clds[0]->type)){
            iCode* code = new_code(3);
            append(code, var);
            append(code, ":=");
            char* value = (char*)malloc(sizeof(char)*(strlen(node->clds[0]->value)+1));
            value[0] = '#';
            strcpy(value+1, node->clds[0]->value);
            append(code, value);
            link2list(tail, code);
        } else {
            strcpy(var, node->clds[0]->value);
        }
    } else if (node->n_cld == 2){
        // MINUS Exp or NOT Exp(cond)
        if (!strcmp("MINUS", node->clds[0]->type)){
            char* tp = new_place();
            translate_Exp(node->clds[1], tp);
            iCode* code = new_code(3);
            append(code, var);
            append(code, ":= #0 -");
            append(code, tp);
            link2list(tail, code);
        } else {
            char* lb1 = new_label();
            char* lb2 = new_label();
            iCode* code1 = new_code(2);
            append(code1, var);
            append(code1, ":= #0");
            link2list(tail, code1);
            translate_cond_Exp(node, lb1, lb2);
            iCode* code2 = new_code(3);
            append(code2, "LABEL");
            append(code2, lb1);
            append(code2, ":");
            link2list(tail, code2);
            iCode* code3 = new_code(2);
            append(code3, var);
            append(code3, ":= #1");
            link2list(tail, code3);
            iCode* code4 = new_code(3);
            append(code4, "LABEL");
            append(code4, lb2);
            append(code4, ":");
            link2list(tail, code4);
        }
    } else if (node->n_cld == 3){
        // Exp ASSIGN\PLUS\MINUS\EQ\AND\OR\LT\LE\GE\GT\NE\MUL\DIV Exp
        // LP Exp RP or ID LP RP
        if (!strcmp("ASSIGN", node->clds[1]->type)){
            char* v = node->clds[0]->clds[0]->value;
            char* tp = new_place();
            translate_Exp(node->clds[2], tp);
            iCode* code1 = new_code(3);
            append(code1, v);
            append(code1, ":=");
            append(code1, tp);
            link2list(tail, code1);
            // iCode* code2 = new_code(3);
            // append(code2, var);
            // append(code2, ":=");
            // append(code2, v);
            // link2list(tail, code2);
        } else if (!strcmp("PLUS", node->clds[1]->type) || !strcmp("MINUS", node->clds[1]->type) || !strcmp("MUL", node->clds[1]->type) || !strcmp("DIV", node->clds[1]->type)){
            char* t1 = new_place();
            char* t2 = new_place();
            translate_Exp(node->clds[0], t1);
            translate_Exp(node->clds[2], t2);
            iCode* code = new_code(5);
            append(code, var);
            append(code, ":=");
            append(code, t1);
            if (!strcmp("PLUS", node->clds[1]->type)){
                append(code, "+");
            } else if (!strcmp("MINUS", node->clds[1]->type)){
                append(code, "-");
            } else if (!strcmp("MUL", node->clds[1]->type)){
                append(code, "*");
            }  else if (!strcmp("DIV", node->clds[1]->type)){
                append(code, "/");
            }
            append(code, t2);
            link2list(tail, code);
        } else if (!strcmp("Exp", node->clds[1]->type)){
            translate_Exp(node->clds[1], var);
        } else if (!strcmp("LP", node->clds[1]->type)){
            if (!strcmp(node->clds[0]->value, "read")){
                iCode* code = new_code(2);
                append(code, "READ");
                append(code, var);
                link2list(tail, code);
            } else {
                iCode* code = new_code(3);
                append(code, var);
                append(code, ":= CALL");
                append(code, node->clds[0]->value);
                link2list(tail, code);
            }
        } else {
            char* lb1 = new_label();
            char* lb2 = new_label();
            iCode* code1 = new_code(2);
            append(code1, var);
            append(code1, ":= #0");
            link2list(tail, code1);
            translate_cond_Exp(node, lb1, lb2);
            iCode* code2 = new_code(3);
            append(code2, "LABEL");
            append(code2, lb1);
            append(code2, ":");
            link2list(tail, code2);
            iCode* code3 = new_code(2);
            append(code3, var);
            append(code3, ":= #1");
            link2list(tail, code3);
            iCode* code4 = new_code(3);
            append(code4, "LABEL");
            append(code4, lb2);
            append(code4, ":");
            link2list(tail, code4);
        }
    } else if (node->n_cld == 4){
        // ID LP ARG RP or Exp LB Exp RB
        if (!strcmp("ID", node->clds[0]->type)){
            if (!strcmp("write", node->clds[0]->value)){
                char* tp = new_place();
                translate_Exp(node->clds[2]->clds[0], tp);
                iCode* code = new_code(2);
                append(code, "WRITE");
                append(code, tp);
                link2list(tail, code);
            } else {
                translate_Args(node->clds[2]);
                iCode* code2 = new_code(3);
                append(code2, var);
                append(code2, ":= CALL");
                append(code2, node->clds[0]->value);
                link2list(tail, code2);
            }
        }
    }
}

void translate_cond_Exp(struct Node* node, char* lbt, char* lbf){
    printf("translate_cond_Exp\n");
    // Exp EQ\AND\OR\LT\LE\GE\GT\NE Exp or NOT Exp
    if (!strcmp(node->clds[1]->type, "AND") || !strcmp(node->clds[1]->type, "OR")){
        char* lb1 = new_label();
        if (!strcmp(node->clds[1]->type, "AND")){
            translate_cond_Exp(node->clds[0], lb1, lbf);
        } else {
            translate_cond_Exp(node->clds[0], lbt, lb1);
        }
        iCode* code = new_code(3);
        append(code, "LABEL");
        append(code, lb1);
        append(code, ":");
        link2list(tail, code);
        translate_cond_Exp(node->clds[2], lbt, lbf);
    } else if (!strcmp(node->clds[0]->type, "NOT")){
        translate_cond_Exp(node->clds[1], lbf, lbt);
    } else {
        char* t1 = new_place();
        char* t2 = new_place();
        translate_Exp(node->clds[0], t1);
        translate_Exp(node->clds[2], t2);
        iCode* code1 = new_code(6);
        append(code1, "IF");
        append(code1, t1);
        if (!strcmp("EQ", node->clds[1]->type)){
            append(code1, "==");
        } else if (!strcmp("LT", node->clds[1]->type)){
            append(code1, "<");
        } else if (!strcmp("LE", node->clds[1]->type)){
            append(code1, "<=");
        } else if (!strcmp("GT", node->clds[1]->type)){
            append(code1, ">");
        } else if (!strcmp("GE", node->clds[1]->type)){
            append(code1, ">=");
        } else if (!strcmp("NE", node->clds[1]->type)){
            append(code1, "!=");
        }
        append(code1, t2);
        append(code1, "GOTO");
        append(code1, lbt);
        link2list(tail, code1);
        iCode* code2 = new_code(2);
        append(code2, "GOTO");
        append(code2, lbf);
        link2list(tail, code2);
    }
}

void translate_Args(struct Node* node){
    printf("translate_Args\n");
    char* tp = new_place();
    translate_Exp(node->clds[0], tp);
    iCode* code = new_code(2);
    append(code, "ARG");
    append(code, tp);
    link2list(tail, code);
    if (node->n_cld == 3){
        translate_Args(node->clds[2]);
    }
}
