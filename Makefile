CC=gcc
FLEX=flex
BISON=bison
splc:
	$(BISON) -d syntax.y
	$(FLEX) lex.l
	$(CC) syntax.tab.c tree.c *Table.c -lfl -o bin/splc
clean:
	@rm -f lex.yy.c syntax.tab.c syntax.tab.h *.out bin/splc
.PHONY: splc