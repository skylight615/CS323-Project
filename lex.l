%{
    #include "syntax.tab.h"
    #include "tree.h"
    #include <string.h>
%}

%option yylineno

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
    return INT;
}
{integerhe} {yylval=createLeaf("INT",yytext);printf("INT %s\n",yytext);return INT;}

-?{digit}{digit}*\.{digit}* {yylval=createLeaf("FLOAT",yytext);return FLOAT;}

{quote}(.|{charhe}){quote} {
    yylval=createLeaf("CHAR",yytext);
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

"int"|"float"|"char" {yylval=createLeaf("TYPE",yytext);return TYPE;}
"struct" {yylval=createLeaf("STRUCT",yytext);return STRUCT;}
"if" {yylval=createLeaf("IF",yytext);return IF;}
"else" {yylval=createLeaf("ELSE",yytext);return ELSE;}
"while" {yylval=createLeaf("WHILE",yytext);return WHILE;}
"return" {yylval=createLeaf("RETURN",yytext);return RETURN;}

-?{digit}({letter_}|{digit})* {printf("ERROR ID\n");return ID;}
{letter_}({letter_}|{digit}){0,31} {yylval=createLeaf("ID",yytext);return ID;}
[\t\r ]+ { /* does nothing when seeing white spaces except new line */}
[\n] {}

"." {yylval=createLeaf("DOT",yytext);return DOT;}
";" {yylval=createLeaf("SEMI",yytext);return SEMI;}
"," {yylval=createLeaf("COMMA",yytext);return COMMA;}
"=" {yylval=createLeaf("ASSIGN",yytext);return ASSIGN;}
"<" {yylval=createLeaf("LT",yytext);return LT;}
"<=" {yylval=createLeaf("LE",yytext);return LE;}
">" {yylval=createLeaf("GT",yytext);return GT;}
">=" {yylval=createLeaf("GE",yytext);return GE;}
"!=" {yylval=createLeaf("NE",yytext);return NE;}
"==" {yylval=createLeaf("EQ",yytext);return EQ;}
"+" {yylval=createLeaf("PLUS",yytext);return PLUS;}
"-" {yylval=createLeaf("MINUS",yytext);return MINUS;}
"*" {yylval=createLeaf("MUL",yytext);return MUL;}
"/" {yylval=createLeaf("DIV",yytext);return DIV;}
"&&" {yylval=createLeaf("AND",yytext);return AND;}
"||" {yylval=createLeaf("OR",yytext);return OR;}
"!" {yylval=createLeaf("NOT",yytext);return NOT;}
"(" {yylval=createLeaf("LP",yytext);return LP;}
")" {yylval=createLeaf("RP",yytext);return RP;}
"[" {yylval=createLeaf("LB",yytext);return LB;}
"]" {yylval=createLeaf("RB",yytext);return RB;}
"{" {yylval=createLeaf("LC",yytext);return LC;}
"}" {yylval=createLeaf("RC",yytext);return RC;}

%%
