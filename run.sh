bison -d yacc.y
flex lex.l
g++ yacc.tab.c lex.yy.c -o qv_compiler -ll
