typedef struct var_
{
    char *name;
    char *type;
    // 是否为结构体域
    int inStruc;
    // 所属的结构体编号
    int strucNum;
    struct var_ *next;
}var;

// add a var into linkedlist
void new_var();

// find the variable if exist
int find();