python.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -ll -w -o python.out
lex.yy.c: python.l 
	lex python.l 
y.tab.c: python.y 
	yacc python.y -dy
clean: 
	rm -rf a.out lex.yy.c y.tab.c y.tab.h python.out
