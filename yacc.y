%{
#include "main.h"

void yyerror(const char *s);
extern int yylex();
extern int yyparse();
extern FILE* output_file;

typedef struct SymbolTableNode {
    variable var;
    struct SymbolTableNode *next;
} SymbolTableNode;

SymbolTableNode *symbol_table = NULL;

void insert_variable(variable var) {
    SymbolTableNode *new_node = (SymbolTableNode *)malloc(sizeof(SymbolTableNode));
    new_node->var = var;
    new_node->next = symbol_table;
    symbol_table = new_node;
}

variable *lookup_variable(char *name) {
    SymbolTableNode *current = symbol_table;
    while (current != NULL) {
        if (strcmp(current->var.name, name) == 0) {
            return &current->var;
        }
        current = current->next;
    }
    return NULL;
}

%}

%union {
    int     intNum;
    float   realNum;
    char* 	str;
    variable var;
    var_type varType;
    
    struct {
        int is_real;
        union {
            int intNum;
            float realNum;
        } value;
    } expr_val;
}


%token <intNum>   	INTEGER_CONST
%token <realNum> 	REAL_CONST
%token <str> 		IDENTIFIER
%token FUN MAIN VAR PRINT PRINTLN RET IF ELSE WHILE FOR TO INT REAL
%token LBRACE RBRACE LBRACKET RBRACKET LPAREN RPAREN SEMICOLON COMMA ASSIGN COLON

%type <str> function statement_list statement variable_declaration assignment print_statement
%type <expr_val> expr value
%type <varType> type

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

program:
    function {
            printf("#include <stdio.h>\n\n%s", $1);
        }
        ;
;

function:
    FUN MAIN LPAREN RPAREN LBRACE statement_list RBRACE{
            $$ = (char*)malloc(strlen($6) + 52);
            sprintf($$, "int main() {\n%s\n\treturn 0;\n}\n", $6);
        }
;

statement_list:
    statement_list statement{
                    char* temp = (char*)malloc(strlen($1) + strlen($2) + 5);
                    strcpy(temp, "\t");
                    strcpy(temp, $1);
                    strcat(temp, "\t");
                    strcat(temp, $2);
                    $$ = temp;
                }
    | statement {
                    char* temp = (char*)malloc(strlen($1) + 3);
                    strcpy(temp, "\t");
                    strcat(temp, $1);
                    $$ = temp;
                }
;

statement:
	variable_declaration {
            $$ = $1;
        }
    | assignment {
            char* temp = (char*)malloc(8);
            sprintf(temp, "int ;\n");
            $$ = temp;
        }
	| print_statement {
            $$ = $1;
        }
;

variable_declaration:
    VAR IDENTIFIER COLON type SEMICOLON
    {
        variable var;
        strcpy(var.name, $2);
        var.type = $4;
        if (lookup_variable($2)) {
            yyerror("Variable already declared");
        } else {
            insert_variable(var);
        }

        if($4 == INT_TYPE){
            $$ = (char*)malloc(strlen(var.name) + 11);
            sprintf($$, "int %s;\n", var.name);
        }else if($4 == REAL_TYPE){
            $$ = (char*)malloc(strlen(var.name) + 13);
            sprintf($$, "float %s;\n", var.name);
        }
    }
    | VAR IDENTIFIER COLON type ASSIGN expr SEMICOLON
    {
        variable var;
        strcpy(var.name, $2);
        var.type = $4;
        if (lookup_variable($2)) {
            yyerror("Variable already declared");
        } else {
            if ($4 == INT_TYPE) {
		        if ($6.is_real) {
		            var.value.ival = $6.value.realNum;
		        } else {
		            var.value.ival = $6.value.intNum;
		        }
                int length = snprintf( NULL, 0, "%d", var.value.ival );
                $$ = (char*)malloc(length + strlen(var.name) + 15);
                sprintf($$, "int %s = %d;\n", var.name, var.value.ival);
            } else if ($4 == REAL_TYPE) {
		        if ($6.is_real) {
		            var.value.rval = $6.value.realNum;
		        } else {
		            var.value.rval = $6.value.intNum;
		        }
                int length = snprintf( NULL, 0, "%f", var.value.rval );
                $$ = (char*)malloc(length + strlen(var.name) + 17);
                sprintf($$, "float %s = %f;\n", var.name, var.value.rval);
            }
            insert_variable(var);
        }
    }
    ;

assignment:
    IDENTIFIER ASSIGN expr SEMICOLON
    {
        variable *var = lookup_variable($1);
        if (!var) {
            yyerror("Variable not declared");
        } else {
            if (var->type == INT_TYPE) {
		        if ($3.is_real) {
		            var->value.ival = $3.value.realNum;
		        } else {
		            var->value.ival = $3.value.intNum;
		        }
                $$ = (char*)malloc(strlen(var->name) + 11);
                sprintf($$, "%s = %d;\n", var->name, var->value.ival);
            } else if (var->type == REAL_TYPE) {
		        if ($3.is_real) {
		            var->value.rval = $3.value.realNum;
		        } else {
		            var->value.rval = $3.value.intNum;
		        }
                $$ = (char*)malloc(strlen(var->name) + 11);
                sprintf($$, "%s = %f;\n", var->name, var->value.rval);
            }
        }
    }
    ;

print_statement:
    PRINT LPAREN expr RPAREN SEMICOLON 		{ 
    	if($3.is_real){
    		printf("// %f\n", $3.value.realNum); 
            int length = snprintf( NULL, 0, "%f", $3.value.realNum );
            $$ = (char*)malloc(length + 18);
            sprintf($$, "printf(\"%f\");\n", $3.value.realNum);
        }
    	else{
    		printf("// %d\n", $3.value.intNum);
            int length = snprintf( NULL, 0, "%d", $3.value.intNum );
            $$ = (char*)malloc(length + 18);
            sprintf($$, "printf(\"%d\");\n", $3.value.intNum);
        }

    }
    | PRINTLN LPAREN expr RPAREN SEMICOLON	{ 
    	if($3.is_real){
    		printf("// %f\n", $3.value.realNum); 
            int length = snprintf( NULL, 0, "%f", $3.value.realNum );
            $$ = (char*)malloc(length + 22);
            sprintf($$, "printf(\"%f\\n\");\n", $3.value.realNum);
        }
    	else{
    		printf("// %d\n", $3.value.intNum);
            int length = snprintf( NULL, 0, "%d", $3.value.intNum );
            $$ = (char*)malloc(length + 22);
            sprintf($$, "printf(\"%d\\n\");\n", $3.value.intNum);
        }
    }
;

type:
    INT { $$ = INT_TYPE; }
    | REAL { $$ = REAL_TYPE; }
    | REAL LBRACKET INT RBRACKET { $$ = ARRAY_TYPE; }
;

expr:
      value                 { $$ = $1; }
    | IDENTIFIER			{
								variable *var = lookup_variable($1);
								if (!var) {
									yyerror("Variable not declared");
								} else {
									if (var->type == INT_TYPE) {
    									$$.is_real = 0;
										$$.value.intNum = var->value.ival;
									} else if (var->type == REAL_TYPE) {
    									$$.is_real = 1;
										$$.value.realNum = var->value.rval;
									}
								}
							}
    | expr '+' expr        
        {
        	float v1 = $1.is_real ? $1.value.realNum : $1.value.intNum;
        	float v2 = $3.is_real ? $3.value.realNum : $3.value.intNum;
				 
        	if($1.is_real || $3.is_real){
    			$$.is_real = 1;
        		$$.value.realNum = (v1 + v2);
        	}else{
    			$$.is_real = 0;
        		$$.value.intNum = (v1 + v2);
        	}
        }
    | expr '-' expr        
        {
        	float v1 = $1.is_real ? $1.value.realNum : $1.value.intNum;
        	float v2 = $3.is_real ? $3.value.realNum : $3.value.intNum;
				 
        	if($1.is_real || $3.is_real){
    			$$.is_real = 1;
        		$$.value.realNum = (v1 - v2);
        	}else{
    			$$.is_real = 0;
        		$$.value.intNum = (v1 - v2);
        	}
        }
    | expr '*' expr        
        {
        	float v1 = $1.is_real ? $1.value.realNum : $1.value.intNum;
        	float v2 = $3.is_real ? $3.value.realNum : $3.value.intNum;
				 
        	if($1.is_real || $3.is_real){
    			$$.is_real = 1;
        		$$.value.realNum = (v1 * v2);
        	}else{
    			$$.is_real = 0;
        		$$.value.intNum = (v1 * v2);
        	}
        }
    | expr '/' expr         
        {
        	float v1 = $1.is_real ? $1.value.realNum : $1.value.intNum;
        	float v2 = $3.is_real ? $3.value.realNum : $3.value.intNum;
				
            if (v2 == 0.0) { 
                yyerror("Error: divisor cannot be zero!"); 
                YYABORT; 
            } else { 
            	if($1.is_real || $3.is_real){
        			$$.is_real = 1;
            		$$.value.realNum = (v1 / v2);
            	}else{
        			$$.is_real = 0;
            		$$.value.intNum = (v1 / v2);
            	}
            } 
        }
    | '-' expr %prec UMINUS          
		{ 
			if($2.is_real)
				$$.value.realNum = $2.value.realNum;
			else
				$$.value.intNum = $2.value.intNum;
		}
    | LPAREN expr RPAREN          
		{ 
			if($2.is_real)
				$$.value.realNum = $2.value.realNum;
			else
				$$.value.intNum = $2.value.intNum;
		}
    ;

value:
      REAL_CONST                 { $$.value.realNum = $1; $$.is_real = 1;}
    | INTEGER_CONST               { $$.value.intNum = (float)$1;  $$.is_real = 0;}
    ;

%%

void yyerror(const char *s) {
    cerr << s << endl;
}


