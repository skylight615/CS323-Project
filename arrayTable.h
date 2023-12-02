typedef struct array_
{
    char *name;
    // int, float, char
    char *type;
    // combine instruc and strucNum to judge if two instruct arrays that have the same name are different
    char *func;
    int size[10];
    int dm;
    int level;
    struct array_* next;
    struct array_* before;
}array;

extern array *array_head, *array_tail;

// add a var into linkedlist
void new_array(char *name, char *type, int* size, char* func);

// find the variable if exist
array* find_array(char *name, char *current_func);
