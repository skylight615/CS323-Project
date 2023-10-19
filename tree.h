extern int yylineno;//行号
extern char* yytext;//词
void yyerror(char *s,...);//错误处理函数

/*抽象语法树的结点*/
struct parsetree
{
    int line; //行号
    char* name;//语法单元的名字
    struct parsetree *l;//左孩子
    struct parsetree *r;//右孩子
    union//共用体用来存放ID/CHAR/INTEGER/FLOAT结点的值
    {
	    char* str;
	    int integer;
	    float flt;
    };
};

/*构造抽象语法树,变长参数，name:语法单元名字；num:变长参数中语法结点个数*/
struct parsetree *newast(char* name,int num,...);

/*遍历抽象语法树，level为树的层数*/
void eval(struct parsetree*,int level);
