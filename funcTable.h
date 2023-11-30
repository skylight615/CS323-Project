typedef struct func_
{
    char *name;
    // 是否为结构体域
    // int inStruc;
    // 所属的结构体编号
    // int strucNum;
    char *rtype; //声明返回值类型
    int va_num;  //记录函数形参个数
    char *va_type[10];
    struct func_ *next;
    struct func_ *before;
}func;

extern func *func_head, *func_tail;

// add a var into linkedlist
void new_func(char *name, char *rtype, char *va_type[], int va_num);

// find the variable if exist
func* find_func(char *name, char *va_type[], int va_num);

