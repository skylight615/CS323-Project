typedef struct struc_
{
    // the position of struc_
    char *name;
    int typeNum;
    int structnum;
    char *type[10];
    struct struc_ *next;
    struct struc_ *before;
}Struct;

extern Struct *struct_head, *struct_tail;

// add a struct into linkedlist
void new_struct(char *name, char *type[], int typeNum);

// find the variable if exist
Struct* find_struct(char *name);

Struct* structual_equal(char *name, char *type[], int typeNum);
int structual_equal2(Struct *a, Struct *b);