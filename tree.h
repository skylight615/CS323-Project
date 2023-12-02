/*抽象语法树的结点*/
struct Node
{
    char* type;//token type
    char* value;//token value, like name
    struct Node* clds[10];
    int n_cld;
    int line;
};

struct Node *createLeaf(char* type,char* value);

/*构造抽象语法树,变长参数，name:语法单元名字；num:变长参数中语法结点个数*/
struct Node *createNode(char* type, int num, struct Node* list[]);

// index means you want to find the first or second ID
char* findToken(struct Node* root, char* type);

int isArray(struct Node* root);

int findSize(struct Node* root, int count, int* size);

void findExp(struct Node* root,int b[]);

/*遍历抽象语法树，level为树的层数*/
void dfs(struct Node* root,int level);

void debug();
