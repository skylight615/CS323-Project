%{
    // In this example, we assume that words can only contain English letters. If there are special symbols such as hyphen or apostrophe, we count multiple times (for example, "isn't" will be counted as two words and "world-class" will also be counted as two words. 
    // just let you know you have macros!
    // C macro tutorial in Chinese: http://c.biancheng.net/view/446.html
    #define EXIT_OK 0
    #define EXIT_FAIL 1
%}
letter [a-zA-Z]
letter_ {letter}|_
digit [0-9]
quote [']
MCE "*/"
MCB "/*"

integerde -?[1-9]{digit}{0,9}|0|[1-9]{digit}{0,9}
integerhe -?0(x|X)(0|(([1-9]|[abcde])({digit}|[abcde]){0,7}))
charhe \\x({digit}|[abcde]){2}
/*
 * Error type:
 * 1. undefined tokens, eg., '@', '#' as non-literal token
 * 2. illegal hex int, eg., 0x5gg
 * 3. illegal hex char, eg., '\x9', '\xt0'
*/

%%

{integerde} {
	if(strtol(yytext,NULL,10)<21478483648 && strtol(yytext,NULL,10)>-21478483649) 			printf("INT %s\n",yytext); 
	}
{integerhe} {printf("INT %s\n",yytext);}

{digit}{digit}*\.{digit}* {printf("FLOAT\n");}

{quote}(.|{charhe}){quote}
{quote}([^\t\r ]+){quote} {printf("ERROR CHAR %s\n",yytext);} 

"//" {
	char c;
	while ((c = input()) != '\n'){}
	unput(c);
	printf("SINGLE COMMENT\n");
}

{MCB}([^{MCB}{MCE}])*{MCE} {printf("MULTIPLE COMMENT\n")}

"int"|"float"|"char" {printf("TYPE\n");}
"struct" {printf("STRUCT\n");}
"if" {printf("IF\n");}
"else" {printf("ELSE\n");}
"while" {printf("WHILE\n");}
"return" {printf("RETURN\n");}
-?{digit}({letter_}|{digit})* {printf("ERROR ID\n");}
{letter_}({letter_}|{digit}){0,31} {printf("ID %s\n",yytext);}
[\t\r\n ]+ { /* does nothing when seeing white spaces except new line */}


"." {printf("DOT\n");}
";" {printf("SEMI\n");}
"," {printf("COMMA\n");}
"=" {printf("ASSIGN\n");}
"<" {printf("LT\n");}
"<=" {printf("LE\n");}
">" {printf("GT\n");}
">=" {printf("GE\n");}
"!=" {printf("NE\n");}
"==" {printf("EQ\n");}
"+" {printf("PLUS\n");}
"-" {printf("MINUS\n");}
"*" {printf("MUL\n");}
"/" {printf("DIV\n");}
"&&" {printf("AND\n");}
"||" {printf("OR\n");}
"!" {printf("NOT\n");}
"(" {printf("LP\n");}
")" {printf("RP\n");}
"[" {printf("LB\n");}
"]" {printf("RB\n");}
"{" {printf("LC\n");}
"}" {printf("RC\n");}

%%
int main(int argc, char **argv){
    char *file_path;
    if(argc < 2){
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAIL;
    } else if(argc == 2){
        file_path = argv[1];
        if(!(yyin = fopen(file_path, "r"))){
            perror(argv[1]);
            return EXIT_FAIL;
        }
        yylex();
        return EXIT_OK;
    } else{
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
