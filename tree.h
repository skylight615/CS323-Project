/*抽象语法树的结点*/
struct Node
{
    char* type;//token type
    char* value;//token value, like ID, INT
    struct Node* clds[10];
    int n_cld;
    int line;
    char* content;//like int a = 1;, the a is the content
};

struct Node *createLeaf(char* type,char* value);

struct Node *createLeafWithContent(char* type,char* value,char* content);

/*构造抽象语法树,变长参数，name:语法单元名字；num:变长参数中语法结点个数*/
struct Node *createNode(char* type, int num, struct Node* list[]);

/*遍历抽象语法树，level为树的层数*/
void dfs(struct Node* root,int level);
