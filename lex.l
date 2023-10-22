%{
    #include "syntax.tab.h"
    #include "tree.h"
    #include <string.h>
%}

letter [a-zA-Z]
letter_ {letter}|_
digit [0-9]
quote "'"
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
	if(strtol(yytext,NULL,10)<21478483648 && strtol(yytext,NULL,10)>-21478483649);
    yylval=createLeaf("INT",yytext);
    printf("INT %s\n",yytext); 
    return INT;
}
{integerhe} {yylval=createLeaf("INT",yytext);printf("INT %s\n",yytext);return INT;}

-?{digit}{digit}*\.{digit}* {yylval=createLeaf("FLOAT",yytext);printf("FLOAT\n");return FLOAT;}

{quote}(.|{charhe}){quote} {
    yylval=createLeaf("CHAR",yytext);
    printf("CHAR %s\n", yytext);
    return CHAR;
    }
{quote}([^\t\r ]+){quote} {printf("ERROR CHAR %s\n",yytext);return CHAR;} 

"//" {
	char c;
	while ((c = input()) != '\n'){}
	unput(c);
	printf("SINGLE COMMENT\n");
}
{MCB}([^{MCB}{MCE}])*{MCE} {printf("MULTIPLE COMMENT\n");}

"int"|"float"|"char" {yylval=createLeaf("TYPE",yytext);printf("TYPE\n");return TYPE;}
"struct" {yylval=createLeaf("STRUCT",yytext);printf("STRUCT\n");return STRUCT;}
"if" {yylval=createLeaf("IF",yytext);printf("IF\n");return IF;}
"else" {yylval=createLeaf("ELSE",yytext);printf("ELSE\n");return ELSE;}
"while" {yylval=createLeaf("WHILE",yytext);printf("WHILE\n");return WHILE;}
"return" {yylval=createLeaf("RETURN",yytext);printf("RETURN\n");return RETURN;}

-?{digit}({letter_}|{digit})* {printf("ERROR ID\n");return ID;}
{letter_}({letter_}|{digit}){0,31} {yylval=createLeaf("ID",yytext);printf("ID %s\n",yytext);return ID;}
[\t\r ]+ { /* does nothing when seeing white spaces except new line */}
[\n] {yylineno++;}

"." {yylval=createLeaf("DOT",yytext);printf("DOT\n");return DOT;}
";" {yylval=createLeaf("SEMI",yytext);printf("SEMI\n");return SEMI;}
"," {yylval=createLeaf("COMMA",yytext);printf("COMMA\n");return COMMA;}
"=" {yylval=createLeaf("ASSIGN",yytext);printf("ASSIGN\n");return ASSIGN;}
"<" {yylval=createLeaf("LT",yytext);printf("LT\n");return LT;}
"<=" {yylval=createLeaf("LE",yytext);printf("LE\n");return LE;}
">" {yylval=createLeaf("GT",yytext);printf("GT\n");return GT;}
">=" {yylval=createLeaf("GE",yytext);printf("GE\n");return GE;}
"!=" {yylval=createLeaf("NE",yytext);printf("NE\n");return NE;}
"==" {yylval=createLeaf("EQ",yytext);printf("EQ\n");return EQ;}
"+" {yylval=createLeaf("PLUS",yytext);printf("PLUS\n");return PLUS;}
"-" {yylval=createLeaf("MINUS",yytext);printf("MINUS\n");return MINUS;}
"*" {yylval=createLeaf("MUL",yytext);printf("MUL\n");return MUL;}
"/" {yylval=createLeaf("DIV",yytext);printf("DIV\n");return DIV;}
"&&" {yylval=createLeaf("AND",yytext);printf("AND\n");return AND;}
"||" {yylval=createLeaf("OR",yytext);printf("OR\n");return OR;}
"!" {yylval=createLeaf("NOT",yytext);printf("NOT\n");return NOT;}
"(" {yylval=createLeaf("LP",yytext);printf("LP\n");return LP;}
")" {yylval=createLeaf("RP",yytext);printf("RP\n");return RP;}
"[" {yylval=createLeaf("LB",yytext);printf("LB\n");return LB;}
"]" {yylval=createLeaf("RB",yytext);printf("RB\n");return RB;}
"{" {yylval=createLeaf("LC",yytext);printf("LC\n");return LC;}
"}" {yylval=createLeaf("RC",yytext);printf("RC\n");return RC;}

%%
