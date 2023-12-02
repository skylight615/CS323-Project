typedef struct var_
{
    // int a = 1; a is the name
    char *name;
    // int is the typr
    char *type;
    // combine instruc and strucNum to judge if two instruct vars that have the same name are different
    int level;
    int from_func;
    struct var_ *next;
    struct var_ *before;
}var;

extern var *var_head, *var_tail;

// add a var into linkedlist
void new_var(char* type, char* name);

// find the variable if exist
var* find_var(char* name);