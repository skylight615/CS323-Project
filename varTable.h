typedef struct var_
{
    // int a = 1; a is the name
    char *name;
    // int is the typr
    char *type;
    // combine instruc and strucNum to judge if two instruct vars that have the same name are different
    // 是否为结构体域
    // int inStruc;
    // 所属的结构体name
    // char* strucName;
    struct var_ *next;
    struct var_ *before;
}var;

var *var_head, *var_tail;

// add a var into linkedlist
void new_var(char* type, char* name);

// find the variable if exist
int find_var(char* type, char* name);