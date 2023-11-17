typedef struct struc_
{
    // the position of struc_
    char *name;
    struct struc_ *next;
    struct struc_ *before;
}Struct;

Struct *struct_head, *struct_tail;

// add a struct into linkedlist
void new_struct(char *name);

// find the variable if exist
int find_struct();