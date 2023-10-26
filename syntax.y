%{
    #include "lex.yy.c"
    void yyerror(const char*);
    struct Node *cldArray[10];
    int yydebug = 1;
    int isCorrect = 1;
%}

%define api.value.type {struct Node *}

/* terminal token */
%token INT FLOAT CHAR TYPE STRUCT IF ELSE WHILE RETURN ID DOT SEMI COMMA
%token ASSIGN LT LE GT GE NE EQ PLUS MINUS MUL DIV AND OR NOT LP RP LB RB
%token LC RC

/* priority of operations */
%right ASSIGN
%left OR
%left AND
%left LT LE GT GE EQ NE
%left PLUS MINUS
%left MUL DIV
%right NEG NOT
%left LP RP LB RB DOT

%nonassoc LOWER_ELSE
%nonassoc ELSE

%%
/* high-level definition */
Program: ExtDefList {cldArray[0] = $1; $$=createNode("Program", 1, cldArray); if(isCorrect){dfs($$,0);}}
    ;
ExtDefList: %empty {$$ = createNode("Empty", 0, cldArray);}
    | ExtDef ExtDefList {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("ExtDefList", 2, cldArray);}
    ;
ExtDef: Specifier ExtDecList SEMI {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("ExtDef", 3, cldArray);}
    | Specifier SEMI {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("ExtDef", 2, cldArray);}
    | Specifier FunDec CompSt {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("ExtDef", 3, cldArray);}
    ;
ExtDecList: VarDec {cldArray[0] = $1; $$=createNode("ExtDecList", 1, cldArray);}
    | VarDec COMMA ExtDecList {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("ExtDecList", 3, cldArray);}
    ;
/* specifier */
Specifier: TYPE {cldArray[0] = $1; $$=createNode("Specifier", 1, cldArray);}
    | StructSpecifier {cldArray[0] = $1; $$=createNode("Specifier", 1, cldArray);}
    ;
StructSpecifier: STRUCT ID LC DefList RC {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5; $$=createNode("StructSpecifier", 5, cldArray);}
    | STRUCT ID {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("StructSpecifier", 2, cldArray);}
    ;
/* declarator */
VarDec: ID {cldArray[0] = $1; $$=createNode("VarDec", 1, cldArray);}
    | VarDec LB INT RB {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("VarDec", 4, cldArray);}
    ;
FunDec: ID LP VarList RP {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("FunDec", 4, cldArray);}
    | ID LP RP {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("FunDec", 3, cldArray);}
    | ID LP error {isCorrect=0;cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=createLeaf("RP",NULL);$$=createNode("FunDec", 3, cldArray);char* text = " MISSING )";printf("%d %s\n",$2->line,text);}
    ;
VarList: ParamDec COMMA VarList {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("VarList", 3, cldArray);}
    | ParamDec {cldArray[0] = $1; $$=createNode("VarList", 1, cldArray);}
    ;
ParamDec: Specifier VarDec {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("ParamDec", 2, cldArray);}
    ;
/* statement */
CompSt: LC DefList StmtList RC {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("CompSt", 4, cldArray);}
    ;
StmtList: %empty {$$ = createNode("Empty", 0, cldArray);}
    | Stmt StmtList {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("StmtList", 2, cldArray);}
    ;
Stmt: Exp SEMI {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("Stmt", 2, cldArray);}
    | CompSt {cldArray[0] = $1; $$=createNode("Stmt", 1, cldArray);}
    | RETURN Exp SEMI {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Stmt", 3, cldArray);}
    | IF LP Exp RP Stmt {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5; $$=createNode("Stmt", 5, cldArray);} %prec LOWER_ELSE
    | IF LP Exp RP Stmt ELSE Stmt {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5; cldArray[5]=$6; cldArray[6]=$7;$$=createNode("Stmt", 7, cldArray);}
    | WHILE LP Exp RP Stmt {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5; $$=createNode("Stmt", 5, cldArray);}
    ;
/* local definition */
DefList: %empty {$$ = createNode("Empty", 0, cldArray);}
    | Def DefList {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("DefList", 2, cldArray);}
    ;
Def: Specifier DecList SEMI {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Def", 3, cldArray);}
    ;
DecList: Dec {cldArray[0] = $1; $$=createNode("DecList", 1, cldArray);}
    | Dec COMMA DecList {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("DecList", 3, cldArray);}
    ;
Dec: VarDec {cldArray[0] = $1; $$=createNode("Dec", 1, cldArray);}
    | VarDec ASSIGN Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Dec", 3, cldArray);}
    ;
/* Expression */
Exp: Exp ASSIGN Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp AND Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp OR Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp LT Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp LE Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp GT Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp GE Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp NE Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp EQ Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp PLUS Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp MINUS Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp MUL Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp DIV Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | LP Exp RP {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | MINUS Exp {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("Exp", 2, cldArray);} %prec NEG
    | NOT Exp {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("Exp", 2, cldArray);}
    | ID LP Args RP {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("Exp", 4, cldArray);}
    | ID LP Args error {isCorrect=0;cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=createLeaf("RP", NULL); $$=createNode("Exp", 4, cldArray);char* text = "MISSING )"; printf("%d %s\n",$3->line,text);}
    | ID LP RP {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp LB Exp RB {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("Exp", 4, cldArray);}
    | Exp LB Exp error RB {yyerror("MISS ]\n");}
    | Exp DOT ID {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | ID {cldArray[0] = $1; $$=createNode("Exp", 1, cldArray);}
    | INT {cldArray[0] = $1; $$=createNode("Exp", 1, cldArray);}
    | FLOAT {cldArray[0] = $1; $$=createNode("Exp", 1, cldArray);}
    | CHAR {cldArray[0] = $1; $$=createNode("Exp", 1, cldArray);}
    ;
Args: Exp COMMA Args {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Args", 3, cldArray);}
    | Exp {cldArray[0] = $1; $$=createNode("Args", 1, cldArray);}
    ;
%%
void yyerror(const char *msg) {
    printf("Error type B at Line ");
} 
int main() {
    yyparse();
}
