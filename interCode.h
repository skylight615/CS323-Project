#ifndef INTERCODE_H
#define INTERCODE_H

typedef struct interCode {
    char** sentence;
    int used;
    int com_num;
    struct interCode* before;
    struct interCode* next;
} iCode;

extern iCode* head;
extern iCode* tail;

void init();
void print_code();
iCode* new_code(int num);
void append(iCode* node, char* unit);
void link2list(iCode* tail, iCode* node);

#endif