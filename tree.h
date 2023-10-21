/*抽象语法树的结点*/
struct Node
{
    char* type;//token type
    char* value;//token value
    struct Node* clds[10];
    int n_cld;
};

struct Node *createLeaf(char* type,char* value);

/*构造抽象语法树,变长参数，name:语法单元名字；num:变长参数中语法结点个数*/
struct Node *createNode(char* type,int num, struct Node* list[]);

/*遍历抽象语法树，level为树的层数*/
void dfs(struct Node* root,int level);
