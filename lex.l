%{
#include "main.h"
#include "customDS.h"
#include "yacc.tab.h"
%}

digit           [0-9]
letter          [a-zA-Z_]
identifier      {letter}({letter}|{digit})*
integer         {digit}+
real            {digit}+"."{digit}+

blank_chars 	([ \f\r\t\v]+)
expressions 	([-+*/])

%x COMMENT
%%

"//"(.)*\n   /* Ignore single-line comments */
"/*"([^*]|\*+[^*/])*\*+"/"  /* Ignore multi-line comments */

"fun"           { return FUN; }
"main"          { return MAIN; }
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

{integer}       { sscanf(yytext, "%d", &(yylval.intNum)); return INTEGER_CONST; }
{real}         	{ sscanf(yytext, "%f", &(yylval.realNum)); return REAL_CONST; }
{identifier}    {  yylval.str = strdup(yytext); return IDENTIFIER; }
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
