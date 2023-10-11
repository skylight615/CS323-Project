%{
    // In this example, we assume that words can only contain English letters. If there are special symbols such as hyphen or apostrophe, we count multiple times (for example, "isn't" will be counted as two words and "world-class" will also be counted as two words. 
    // just let you know you have macros!
    // C macro tutorial in Chinese: http://c.biancheng.net/view/446.html
    #define EXIT_OK 0
    #define EXIT_FAIL 1

    // global variables
    int chars = 0;
    int words = 0;
    int lines = 0;
%}
letter [a-zA-Z]

%%
/*
 * Error type:
 * 1. undefined tokens, eg., '@', '#' as non-literal token
 * 2. illegal hex int, eg., 0x5gg
 * 3. illegal hex char, eg., '\x9', '\xt0'
*/

// value
INT     -> /* integer in 32-bits (decimal or hexadecimal) */
FLOAT   -> /* floating point number (only dot-form) */
CHAR    -> /* single character (printable or hex-form) */

ID      -> /* identifier */

TYPE    -> int | float | char // key word
STRUCT  -> struct
IF      -> if
ELSE    -> else
WHILE   -> while
RETURN  -> return
DOT     -> .
SEMI    -> ;
COMMA   -> ,
ASSIGN  -> =
LT      -> <
LE      -> <=
GT      -> >
GE      -> >=
NE      -> !=
EQ      -> ==
PLUS    -> +
MINUS   -> -
MUL     -> *
DIV     -> /
AND     -> &&
OR      -> ||
NOT     -> !
LP      -> (
RP      -> )
LB      -> [
RB      -> ]
LC      -> {
RC      -> }

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
	printf("%-8s%-8s%-8s%s\n", "#lines", "#words", "#chars", "file path");
        printf("%-8d%-8d%-8d%s\n", lines, words, chars, file_path);
        return EXIT_OK;
    } else{
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
