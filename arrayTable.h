typedef struct array_
{
    char *name;
    // int, float, char
    char *type;
    // combine instruc and strucNum to judge if two instruct arrays that have the same name are different
    // 是否为结构体域
    // int inStruc;
    // 所属的结构体编号
    // int strucNum;
    int size[10];
    int dm;
    int level;
    struct array_* next;
    struct array_* before;
}array;

array *array_head, *array_tail;

// add a var into linkedlist
void new_array(char *name, char *type, int* size);

// find the variable if exist
array* find_array(char *name);
