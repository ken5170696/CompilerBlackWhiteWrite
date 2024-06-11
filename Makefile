LEX=flex
YACC=bison
CC=g++
OBJECT=main

$(OBJECT): lex.yy.o yacc.tab.o symbolTable.o customDS.o main.o 
		$(CC) customDS.o symbolTable.o main.o lex.yy.o yacc.tab.o -o $(OBJECT)

lex.yy.o: lex.yy.c yacc.tab.h main.h
		$(CC) -c lex.yy.c

yacc.tab.o: yacc.tab.c main.h
		$(CC) -c yacc.tab.c

yacc.tab.c yacc.tab.h: yacc.y
		$(YACC) -d yacc.y

lex.yy.c: lex.l
		$(LEX) lex.l

main.o: main.cpp
		$(CC) -c main.cpp

symbolTable.o: ./Utilities/symbolTable.cpp
		$(CC) -c ./Utilities/symbolTable.cpp

customDS.o: ./Utilities/customDS.cpp
		$(CC) -c ./Utilities/customDS.cpp

clean: 
	rm *.o yacc.tab.* lex.yy.c
