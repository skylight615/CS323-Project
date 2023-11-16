typedef struct struc_
{
    char *name;
    char *type;
    // 是否为结构体域
    int inStruc;
    // 所属的结构体编号
    int strucNum;
    struct struc_ *next;
}struc;

// add a struct into linkedlist
void new_struct();

// find the variable if exist
int find();