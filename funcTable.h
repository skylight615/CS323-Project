typedef struct func_
{
    int tag; //0表示未定义，1表示定义
    char *name;
    char *type;
    // 是否为结构体域
    int inStruc;
    // 所属的结构体编号
    int strucNum;
    char *rtype; //声明返回值类型
    int va_num;  //记录函数形参个数
    char *va_type[10];
    struct func_ *next;
}func;

// add a var into linkedlist
void new_func();

// find the variable if exist
int find();

