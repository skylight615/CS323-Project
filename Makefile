CC=gcc
FLEX=flex
BISON=bison
parse:
	$(BISON) -d syntax.y
	$(FLEX) lex.l
	$(CC) syntax.tab.c tree.c -lfl -o parse.out
clean:
	@rm -f lex.yy.c syntax.tab.c syntax.tab.h *.out
.PHONY: parse
