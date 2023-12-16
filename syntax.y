%{
    #include "lex.yy.c"
    #include "arrayTable.h"
    #include "varTable.h"
    #include "funcTable.h"
    #include "structTable.h"
    #include "stdlib.h"
    #include "translate.h"
    void yyerror(const char*);
    struct Node *cldArray[10];
    int yydebug = 1;
    int isCorrect = 1;
    int paraCount = 0;
    char* va_type[10];
    int dec_type[10];// 1 is array, 0 is var 
    int *array_size[10];
    int dec_num = 0;
    char* dec_id[10];
    char* structTypes[10];
    int structTypeNum = 0;
    int varnum=0;
    char* var_name[10];
    int usefunc=0;
    char* retype;
    int func_arg=0;
    char* functype;
    int return_line=0;
    extern int LCnum;
    extern int inStruct;
    extern int func_num;
    extern int struct_num;
%}

%define api.value.type {struct Node *}

/* terminal token */
%token INT FLOAT CHAR TYPE STRUCT IF ELSE WHILE RETURN ID DOT SEMI COMMA INCLUDE FILEIN DEFINEIN
%token ASSIGN LT LE GT GE NE EQ PLUS MINUS MUL DIV AND OR NOT LP RP LB RB
%token ERROR

/* priority of operations */
%right ASSIGN
%left OR
%left AND
%left LT LE GT GE EQ NE
%left PLUS MINUS
%left MUL DIV
%right NEG NOT
%left LP RP LB RB DOT LC RC

%nonassoc LOWER_ELSE
%nonassoc ELSE

%nonassoc REDUCE
%nonassoc SHIFT
%%
/* high-level definition */
Program: ExtDefList {cldArray[0] = $1; $$=createNode("Program", 1, cldArray); dfs($$,0); translate_Program($$);}
    | HeadList ExtDefList {cldArray[0] = $1; cldArray[1] = $2;$$=createNode("Program", 2, cldArray); 
        if(isCorrect==1)dfs($$,0);}
    ;
HeadList: %empty {$$ = createNode("Empty", 0, cldArray);}
    | Head HeadList {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("HeadList", 2, cldArray);}
    ;
Head: INCLUDE FILEIN {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("Head", 2, cldArray);}
    | INCLUDE ERROR {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("Head", 2, cldArray); isCorrect=0;}
    | INCLUDE error {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("Head", 2, cldArray);
        isCorrect=0;char* text = "Not a head file";printf("%d: %s\n",$2->line,text);}
    | DEFINEIN ID INT {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Head", 3, cldArray);}
    | DEFINEIN ID FLOAT {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Head", 3, cldArray);}
    | DEFINEIN ID CHAR {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Head", 3, cldArray);}
    | DEFINEIN ID ID {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Head", 3, cldArray);}
    | DEFINEIN ID ERROR {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Head", 3, cldArray);
         isCorrect=0;}
    | DEFINEIN error {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("Head", 2, cldArray);
        isCorrect=0;char* text = "Not a head macro";printf("%d: %s\n",$1->line,text);}
    | DEFINEIN TransPara Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Head", 3, cldArray);}
    ;
TransPara: ID LP IdList RP {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3;cldArray[3]=$4;
     $$=createNode("TransPara", 4, cldArray);}
    | ID LP IdList error {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3;cldArray[3]=$4;
         $$=createNode("TransPara", 4, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",$2->line,text);}
    ;
IdList: ID {cldArray[0] = $1; $$=createNode("IdList", 1, cldArray);}
    | ID COMMA IdList {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Head", 3, cldArray);}
    | %empty {$$ = createNode("Empty", 0, cldArray);}
    ;
ExtDefList: %empty {$$ = createNode("Empty", 0, cldArray);}
    | ExtDef ExtDefList {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("ExtDefList", 2, cldArray);}
    ;
ExtDef: Specifier ExtDecList SEMI {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("ExtDef", 3, cldArray);}
    | Specifier SEMI {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("ExtDef", 2, cldArray);}
    | Specifier FunDec CompSt {
        cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3;
        $$=createNode("ExtDef", 3, cldArray);
        // add the function into funcTable
        char* name = findToken($2, "ID");
        char* rtype = findToken($1, "TYPE");
        func* find=find_func_name_only(name);
        if(find!=NULL){
            isCorrect=0;
            printf("Error type 4 at Line %d: %s is redefined\n",$1->line,name);
        }else{ new_func(name, rtype, va_type, paraCount);}
        for (int i = 0; i < paraCount; i++){
            free(va_type[i]);
        }
        paraCount = 0;

        char* typetemp=findToken($1,"TYPE");
        if(strcmp(typetemp,retype)!=0){
            isCorrect=0;
            printf("Error type 8 at Line %d: incompatiable return type\n",return_line);
        }
    }
    | Specifier error {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("ExtDef", 2, cldArray);
        isCorrect=0;char* text = "Missing semicolon ';'";printf("%d: %s\n",$2->line,text);}
    ;
ExtDecList: VarDec {cldArray[0] = $1; $$=createNode("ExtDecList", 1, cldArray);}
    | VarDec COMMA ExtDecList {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("ExtDecList", 3, cldArray);}
    ;
/* specifier */
Specifier: TYPE {cldArray[0] = $1; $$=createNode("Specifier", 1, cldArray);}
    | StructSpecifier {cldArray[0] = $1; $$=createNode("Specifier", 1, cldArray);}
    ;
StructSpecifier: STRUCT ID LC DefList RC {
        cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5; 
        $$=createNode("StructSpecifier", 5, cldArray);
        if(find_struct($2->value)!=NULL){
            isCorrect=0;
            printf("Error type 15 at Line %d: redefine the same structure type\n",$1->line);
        }else new_struct($2->value, structTypes, structTypeNum);
        for (int i = 0; i < structTypeNum; i++){
            free(structTypes[i]);
        }
        structTypeNum = 0;
        inStruct = 0;
    }
    | STRUCT ID LC DefList error {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5; $$=createNode("StructSpecifier", 5, cldArray);
        isCorrect=0;char* text = "Missing closing brace '}'";printf("%d: %s\n",yylineno,text);}
    | STRUCT ID {inStruct = 0; cldArray[0] = $1; cldArray[1] = $2; $$=createNode("StructSpecifier", 2, cldArray);}
    ;
/* declarator */
VarDec: ID {cldArray[0] = $1; $$=createNode("VarDec", 1, cldArray);}
    | VarDec LB INT RB {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("VarDec", 4, cldArray);}
    | ERROR {cldArray[0]=$1; $$=createNode("Exp", 1, cldArray); isCorrect=0;}
    ;
FunDec: ID LP VarList RP {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("FunDec", 4, cldArray);}
    | ID LP RP {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("FunDec", 3, cldArray);}
    | ID LP error {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=createLeaf("RP",NULL);$$=createNode("FunDec", 3, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",$2->line,text);}
    | ID LP VarList error {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("FunDec", 4, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",$2->line,text);}
    ;
VarList: ParamDec COMMA VarList {
        cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; 
        $$=createNode("VarList", 3, cldArray);
        char* type = findToken($1, "TYPE");
        va_type[paraCount] = (char*)malloc(sizeof(char)*strlen(type));
        strcpy(va_type[paraCount], type);
        paraCount++;
    }
    | ParamDec {
        cldArray[0] = $1; 
        $$=createNode("VarList", 1, cldArray);
        // record the func parameter
        char* type = findToken($$, "TYPE");
        va_type[paraCount] = (char*)malloc(sizeof(char)*strlen(type));
        strcpy(va_type[paraCount], type);
        paraCount++;
    }
    ;
ParamDec: Specifier VarDec {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("ParamDec", 2, cldArray);
            char* type = findToken($1, "TYPE");
            char* id =findToken($2,"ID");
            new_var(type, id);
            }
    ;
/* statement */
CompSt: LC DefList StmtList RC {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("CompSt", 4, cldArray);}
    ;
StmtList: %empty {$$ = createNode("Empty", 0, cldArray);}
    | Stmt StmtList {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("StmtList", 2, cldArray);}
    ;
Stmt: Exp SEMI {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("Stmt", 2, cldArray);}
    | CompSt {cldArray[0] = $1; $$=createNode("Stmt", 1, cldArray);}
    | RETURN Exp SEMI {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Stmt", 3, cldArray);
            char* id=findToken($2,"ID");
            return_line=$1->line;
            if(id==NULL){ // return is num
                char* isint=findToken($2,"INT");
                if(isint != NULL) retype="int";
                else retype="float";
            } else{   // return is an id or array or func
                func* func= find_func_name_only(id); array* array= find_array(id); var* var= find_var(id);
                if(func !=NULL){
                    retype=func->rtype;
                }else if(array !=NULL){
                    retype=array->type;
                    if(isArray($2)!=array->dm){
                        isCorrect=0;
                        printf("Error type 10 at line %d: indexing on non-array variable\n",$1->line);
                    }
                    
                }else if(var!=NULL){
                    retype=var->type;
                }else{
                    isCorrect=0;
                    printf("Error type 1 at Line %d: %s is used without a definition\n",$1->line,id);
                }
            }
            varnum=0;
            }
    | RETURN Exp error {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Stmt", 3, cldArray);
        isCorrect=0;char* text = "Missing semicolon ';'";printf("%d: %s\n",$2->line,text);}
    | IF LP Exp RP Stmt %prec LOWER_ELSE{cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5; $$=createNode("Stmt", 5, cldArray);}
    | IF LP Exp error Stmt %prec LOWER_ELSE{cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5; $$=createNode("Stmt", 5, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",$2->line,text);} 

    | IF LP Exp RP Stmt ELSE Stmt {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5; cldArray[5]=$6; cldArray[6]=$7;$$=createNode("Stmt", 7, cldArray);}
    | WHILE LP Exp RP Stmt {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5; $$=createNode("Stmt", 5, cldArray);}
    | WHILE LP Exp error Stmt {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5; $$=createNode("Stmt", 5, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",$2->line,text);}

    | Exp error {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("Stmt", 2, cldArray); isCorrect=0;char* text = "Missing semicolon ';'";printf("%d: %s\n",$1->line,text);}
    ;
/* local definition */
DefList: %empty {$$ = createNode("Empty", 0, cldArray);}
    | Def DefList {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("DefList", 2, cldArray);}
    ;
Def: Specifier DecList SEMI {
        cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Def", 3, cldArray);

        // new a var or an array
        char* type = findToken($1, "TYPE");
        char* s;
        if (type == NULL){
            s = findToken($1, "ID");
        }
        for (int i = 0; i < dec_num; i++){
            if (dec_type[i]){
                // array
                array* arr=find_array(dec_id[i]);
                if(arr!=NULL){
                    isCorrect=0;
                    printf("Error type 3 at Line %d: variable %s is redefined in the same scope\n",$1->line,dec_id[i]);
                }
                else (type == NULL) ? new_array(dec_id[i],s , array_size[i]) : new_array(dec_id[i], type, array_size[i]);
                free(array_size[i]);
            } else {
                // var or struct
                var* v=find_var_struct(dec_id[i],struct_num);
                
                if(v!=NULL){
                    isCorrect=0;
                    printf("Error type 3 at Line %d: variable %s is redefined in the same scope\n",$1->line,dec_id[i]);
                }
                else{
                    (type == NULL) ? new_var(s, dec_id[i]) : new_var(type, dec_id[i]);}
            }
            free(dec_id[i]);
        }
        int b[4]={0};
        findExp($2,b);
        int cmp=-dec_num;
        int minint=isArray($2);
        for(int i=0;i<4;i++){
            if(i==1) b[i]-=minint;
            cmp+=b[i];
        }
        if(type!=NULL && cmp!=0){
            int tot=0;
            char* lefttype=type;
            if(usefunc>0){
                if(usefunc==1 && strcmp(lefttype,functype)!=0){
                    isCorrect=0;
                    printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n",$1->line);
                }
                usefunc=0;
            }else{
                for(int i=0;i<varnum;i++){
                    var* temp=find_var(var_name[i]);
                    if(temp==NULL || strcmp(lefttype,temp->type)==0){ 
                    tot++;
                    }
                    free(var_name[i]);
                }
                if(strcmp(lefttype,"int")==0){
                    tot+=b[1];
                }else if(strcmp(lefttype,"float")==0){
                    tot+=b[2];
                }else{tot+=b[3];}
                if(tot!=cmp){
                    printf("%d---%d\n",tot,cmp);
                    isCorrect=0;
                    printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n",$1->line);
                    if(cmp!=1)  printf("Error type 7 at Line %d: unmatching operands\n",$1->line);
                }
                }
                
        }
        varnum=0;
        dec_num = 0;
        if (inStruct) {
            structTypes[structTypeNum] = (char*)malloc(sizeof(char)*strlen(type));
            strcpy(structTypes[structTypeNum++], type);
        }
        
    }
    | Specifier DecList error {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Def", 3, cldArray);
        isCorrect=0;char* text = "Missing semicolon ';'";printf("%d: %s\n",$2->line,text);}
    ;
DecList: Dec {cldArray[0] = $1; $$=createNode("DecList", 1, cldArray);}
    | Dec COMMA DecList {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("DecList", 3, cldArray);}
    ;
Dec: VarDec {
        cldArray[0] = $1; 
        $$=createNode("Dec", 1, cldArray);
        int type = isArray($1);
        if (type == 0){
            // var
            dec_type[dec_num] = 0;
        } else {
            // array
            dec_type[dec_num] = 1;
            array_size[dec_num] = (int*)malloc(sizeof(int)*10);
            int c = findSize($1, 0, array_size[dec_num]);
            array_size[dec_num][0] = c;
        }
        char* id = findToken($1, "ID");
        dec_id[dec_num] = (char*)malloc(sizeof(char)*strlen(id));
        strcpy(dec_id[dec_num], id);
        dec_num++;
    }
    | VarDec ASSIGN Exp {
        cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; 
        $$=createNode("Dec", 3, cldArray);
        int type = isArray($1);
        if (type == 0){
            // var
            dec_type[dec_num] = 0;
        } else {
            // array
            dec_type[dec_num] = 1;
            array_size[dec_num] = (int*)malloc(sizeof(int)*10);
            int c = findSize($1, 0, array_size[dec_num]);
            array_size[dec_num][0] = c;
        }
        char* id = findToken($1, "ID");
        dec_id[dec_num] = (char*)malloc(sizeof(char)*strlen(id));
        strcpy(dec_id[dec_num], id);
        dec_num++;
        for(int i=0;i<varnum;i++){
            var* temp=find_var(var_name[i]);
            if(temp== NULL){
                isCorrect=0;
                printf("Error type 1 at Lind %d: %s is used without a definition\n",$2->line,var_name[i]);
            }
        }
        
    }
    ;
/* Expression */
Exp: Exp ASSIGN Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);
        int b1[4]={0};
        findExp($1,b1);
        if(b1[0]==0){
            printf("Error type 6 at Line %d: rvalue appears on the left-side of assignment\n",$1->line);
        }
        else{
            char* id=var_name[0];
            var* v=find_var_struct(id,struct_num);
            char* lefttype;
            int num=1;
            Struct* s;
            if(v !=NULL){ // left is var or struct
                lefttype=v->type;
                s = find_struct(lefttype);
                int sn=0;
                while(s!=NULL){ // aa.weight
                    sn=s->structnum;
                    if(num==b1[0])break;
                    id=var_name[num];
                    v=find_var_struct(id,sn);
                    num++;
                    if(v==NULL){
                        printf("Error type 14 at Line %d: accessing an undefined structure member\n",$2->line);break;}
                    lefttype=v->type;
                    s = find_struct(lefttype);
                }if(num!=b1[0]){
                    isCorrect=0;
                    v=find_var(id);
                    if(v==NULL)printf("Error type 14 at Line %d: accessing an undefined structure member\n",$2->line);
                    else printf("Error type 13 at Line %d: accessing with non-struct variable\n",$2->line);
                    num=b1[0];
                }
            }
            else{ // left is array or not exists
                array* arr=find_array(id);
                if(arr!=NULL){
                    lefttype=arr->type;
                    for(;num<b1[0];num++){
                        array* temparr=find_array(var_name[num]); var* tempvar=find_var(var_name[num]);
                        if(temparr!=NULL && strcmp(temparr->type,"int")!=0 ||tempvar!= NULL && strcmp(tempvar->type,"int")!=0){
                            isCorrect=0;
                            printf("Error type 12 at Line %d: indexing by non-integer\n",$1->line);
                        }
                        if(temparr==NULL &&tempvar== NULL && usefunc!=1){isCorrect=0;printf("Error type 1 at Line %d: %s is used without a definition\n",$2->line,var_name[num]);}
                    }
                    
                }else {isCorrect=0;printf("Error type 1 at Line %d: %s is used without a definition\n",$2->line,id); lefttype="int";}

            }
            if(isArray($3)==0){  //right has no array
                int b[4]={0};
                findExp($3,b);
                int cmp=0;
                for(int i=0;i<4;i++){
                    cmp+=b[i];
                }
                int tot=0;
                int sn=struct_num;
                Struct* s2;
                for(int i=num;i<varnum;i++){
                    var* temp=find_var_struct(var_name[i],sn);
                    if(temp !=NULL){ 
                        s2 = find_struct(temp->type);
                        if(s2 ==NULL){
                            if(strcmp(lefttype,temp->type)==0){ 
                                tot++;
                            }
                        }else{
                            sn=s2->structnum;
                            if(i!=varnum-1)cmp--;
                            else{
                                if(s!=NULL && structual_equal2(s,s2)){
                                    if(strcmp(lefttype,s2->name)==0){tot++;}
                                    
                                }
                            }
                        }
                    }else{
                        array* temp2=find_array(var_name[i]);
                        if(temp2!=NULL && strcmp(lefttype,temp2->type)==0){ 
                            tot++;
                        }else{
                            cmp--;isCorrect=0; var* t=find_var(var_name[i]);
                            if(t==NULL)printf("Error type 1 at Line %d: %s is used without a definition\n",$2->line,var_name[i]);
                            else printf("Error type 13 at Line %d: accessing with non-struct variable\n",$2->line);
                        }
                    } 
                }
                if(strcmp(lefttype,"int")==0){
                    tot+=b[1];
                }else if(strcmp(lefttype,"float")==0){
                    tot+=b[2];
                }else{tot+=b[3];}
                if(tot!=cmp){
                    isCorrect=0;
                    printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n",$1->line);
                    if(cmp!=1)  printf("Error type 7 at Line %d: unmatching operands\n",$1->line);
                }
            }else{ //right is array
                array* temparr=find_array(var_name[num]);
                num++;
                if(temparr!=NULL){
                    if(strcmp(temparr->type,lefttype)!=0){
                        isCorrect=0;printf("Error type 5 at Line %d: unmatching types on both sides of assignment\n",$2->line);
                        }
                    for(;num<varnum;num++){
                        array* temparr=find_array(var_name[num]); var* tempvar=find_var(var_name[num]);
                        if(temparr!=NULL && strcmp(temparr->type,"int")!=0 ||tempvar!= NULL && strcmp(tempvar->type,"int")!=0){
                        isCorrect=0;
                        printf("Error type 12 at Line %d: indexing by non-integer\n",$1->line);
                        }
                        if(temparr==NULL &&tempvar== NULL){
                            isCorrect=0;printf("Error type 1 at Line %d: %s is used without a definition\n",$2->line,var_name[num]);}
                    }
                    int c[4];
                    findExp($3,c);
                    if(strcmp(lefttype,"int")==0 && (c[2]!=0||c[3]!=0)){
                        isCorrect=0;printf("Error type 5 at Line %d: unmatching types on both sides of assignment\n",$2->line);
                    }
                }else{
                     isCorrect=0;printf("Error type 1 at Line %d: %s is used without a definition\n",$2->line,var_name[num--]);
                }
                
            }
        }
        for(int i=0;i<varnum;i++){
            free(var_name[i]);
        }
        varnum=0;
        }
    | Exp AND Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp OR Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);}
    | Exp ERROR Exp {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray); isCorrect=0;}
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
    | LP Exp error {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",$2->line,text);}
    | MINUS Exp {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("Exp", 2, cldArray);} %prec NEG
    | NOT Exp {cldArray[0] = $1; cldArray[1] = $2; $$=createNode("Exp", 2, cldArray);}
    | ID LP Args RP {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("Exp", 4, cldArray);
            func* func=find_func_name_only($1->value);
            if(func==NULL){
                usefunc=2;
                isCorrect=0;
                printf("Error type 2 at Line %d: %s is invoked without a definition\n",$1->line,$1->value);
            }else{
                usefunc=1;
                int xingcan=func->va_num;functype=func->rtype;
                if(xingcan!=func_arg){
                    printf("Error type 9 at Line %d: invalid argument number, except %d, got %d\n",$1->line,xingcan,func_arg);
                    isCorrect=0;
                }
            }

            func_arg=0;
            }
    | ID LP Args error {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("Exp", 4, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",$2->line,text);}
    | ID LP RP {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);
            func* func=find_func_name_only($1->value);
            if(func==NULL){
                var* temp =find_var($1->value);isCorrect=0;
                if(temp!=NULL){
                    var_name[varnum] = (char*)malloc(sizeof(char)*strlen($1->value));
                    strcpy(var_name[varnum], $1->value);
                    varnum++;
                    printf("Error type 11 at Line %d: invoking non-function variable\n",$1->line);
                }
                else {usefunc=1;printf("Error type 2 at Line %d: %s is invoked without a definition\n",$1->line,$1->value);}
            }else{
                int xingcan=func->va_num;usefunc=1;functype=func->rtype;
                if(xingcan!=0){
                    isCorrect=0;
                    printf("Error type 9 at Line %d: invalid argument number, except %d, got 0\n",$1->line,xingcan);
                }
            }
            }
    | Exp LB Exp RB {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; cldArray[3]=$4; $$=createNode("Exp", 4, cldArray);
            int a[4];findExp($3,a);if(a[2]!=0 ||a[3]!=0){
                isCorrect=0;printf("Error type 12 at Line %d: indexing by non-integer\n",$1->line);
            }}
    | Exp DOT ID {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Exp", 3, cldArray);
        char* id =$3->value;
        var_name[varnum] = (char*)malloc(sizeof(char)*strlen(id));
        strcpy(var_name[varnum], id);
        varnum++;}
    | ID {cldArray[0] = $1; $$=createNode("Exp", 1, cldArray);
        char* id =$1->value;
        var_name[varnum] = (char*)malloc(sizeof(char)*strlen(id));
        strcpy(var_name[varnum], id);
        varnum++;}
    | INT {cldArray[0] = $1; $$=createNode("Exp", 1, cldArray);}
    | FLOAT {cldArray[0] = $1; $$=createNode("Exp", 1, cldArray);}
    | CHAR {cldArray[0] = $1; $$=createNode("Exp", 1, cldArray);}
    | ERROR {cldArray[0]=$1; $$=createNode("Exp", 1, cldArray); isCorrect=0;}
    ;
Args: Exp COMMA Args {cldArray[0] = $1; cldArray[1] = $2; cldArray[2]=$3; $$=createNode("Args", 3, cldArray);func_arg++;}
    | Exp {cldArray[0] = $1; $$=createNode("Args", 1, cldArray); func_arg++;}
    ;
%%
void yyerror(const char *s) {
    printf("Error type B at Line ");
}
int main(int argc, char *argv[]) {
    if(argc < 2) return 1;
    // init tables
    var_head = (var*)malloc(sizeof(var));
    var_tail = (var*)malloc(sizeof(var));
    var_head->next = var_tail;
    var_tail->before = var_head;
    struct_head = (Struct*)malloc(sizeof(Struct));
    struct_tail = (Struct*)malloc(sizeof(Struct));
    struct_head->next = struct_tail;
    struct_tail->before = struct_head;
    func_head = (func*)malloc(sizeof(func));
    func_tail = (func*)malloc(sizeof(func));
    func_head->next = func_tail;
    func_tail->before = func_head;
    array_head = (array*)malloc(sizeof(array));
    array_tail = (array*)malloc(sizeof(array));
    array_head->next = array_tail;
    array_tail->before = array_head;

    FILE *f = fopen(argv[1], "r");
    if(!f) {
        perror(argv[1]);
        return 1;
    }

    yyrestart(f);
    yylineno = 1;
    yyparse();

    return 0;
}