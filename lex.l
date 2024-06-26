%{
#include "main.h"
#include "./Utilities/customDS.h"
#include "./Utilities/symbolTable.h"
#include "yacc.tab.h"
%}

digit           [0-9]
letter          [a-zA-Z_]
identifier      {letter}({letter}|{digit})*
integer         {digit}+
real            {digit}+"."{digit}+
strLit          \"[^\"]*\"

blank_chars 	([ \f\r\t\v]+)
expressions 	([-+*/])

%%

"//"(.)*\n   /* Ignore single-line comments */
"/*"([^*]|\*+[^*/])*\*+"/"  /* Ignore multi-line comments */

"fun"           { return FUN; }
"var"           { return VAR; }
"int"           { return INT; }
"real"          { return REAL; }
"print"         { return PRINT; }
"println"       { return PRINTLN; }
"ret"           { return RET; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"to"            { return TO; }
"return"        { return RETURN; }

{strLit}        {
    StringWrapper* temp = new StringWrapper();
    temp->str = strdup(yytext);
    yylval.cppStr = temp; 
    return STRING_CONST; 
}
{integer}       { sscanf(yytext, "%d", &(yylval.intNum)); return INTEGER_CONST; }
{real}         	{ sscanf(yytext, "%f", &(yylval.realNum)); return REAL_CONST; }
{identifier}    { 
    StringWrapper* temp = new StringWrapper();
    temp->str = strdup(yytext);
    yylval.cppStr = temp; 
    return IDENTIFIER; 
}
{expressions}   { return yytext[0]; }

"="             { return ASSIGN; }

"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"("             { return LPAREN; }
")"             { return RPAREN; }
";"             { return SEMICOLON; }
":"             { return COLON; }
","             { return COMMA; }
"\\n"            { return NEWLINE; }

{blank_chars}   { ; }
\n              { ; }

%%

int yywrap(void) {
    return 1;
}
