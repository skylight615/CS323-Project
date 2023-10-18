%{
    #include "lex.yy.c"
    void yyerror(const char*);
%}
%%
%%
void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}
int main() {
    yyparse();
}
