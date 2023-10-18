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
quotes [']
MCE "*/"
MCB "/*"

/*
 * Error type:
 * 1. undefined tokens, eg., '@', '#' as non-literal token
 * 2. illegal hex int, eg., 0x5gg
 * 3. illegal hex char, eg., '\x9', '\xt0'
*/

%%
INT     -> /* integer in 32-bits (decimal or hexadecimal) */
{digit}{1,10}|(0x({digit}|[abcde]){1,8})
{digit}{digit}*\.{digit}* {printf("FLOAT\n");}
CHAR    -> /* single character (printable or hex-form) */

{quotes}.{quotes} {printf("CHAR\n");} /*fixme: not include the hex form */

{digit}({letter_}|{digit})* {printf("ERROR ID");}
{letter_}({letter_}|{digit}){0,31} {printf("ID");}

"//" {
	char c;
	while ((c = input()) != '\n'){}
	unput(c);
	printf("SINGLE COMMENT\n");
}

{MCB}([^{MCB}{MCE}])*{MCE} {printf("MULTIPLE COMMENT\n")}

int|float|char {printf("TYPE\n");}
struct {printf("STRUCT\n");}
if {printf("IF\n");}
else {printf("ELSE\n");}
while {printf("WHILE\n");}
return {printf("RETURN\n");}
. {printf("DOT\n");}
; {printf("SEMI\n");}
, {printf("COMMA\n");}
= {printf("ASSIGN\n");}
< {printf("LT\n");}
<= {printf("LE\n");}
> {printf("GT\n");}
>= {printf("GE\n");}
!= {printf("NE\n");}
== {printf("EQ\n");}
+ {printf("PLUS\n");}
- {printf("MINUS\n");}
* {printf("MUL\n");}
/ {printf("DIV\n");}
&& {printf("AND\n");}
|| {printf("OR\n");}
! {printf("NOT\n");}
\( {printf("LP\n");}
\) {printf("RP\n");}
\[ {printf("LB\n");}
\] {printf("RB\n");}
{ {printf("LC\n");}
} {printf("RC\n");}

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
