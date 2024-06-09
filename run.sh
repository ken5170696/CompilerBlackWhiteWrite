bison -d yacc.y
flex lex.l
g++ -c yacc.tab.c
g++ -c lex.yy.c
g++ -c main.cpp
g++ main.o lex.yy.o yacc.tab.o -o main
./main
