%{
#include "main.h"

void yyerror(const char *s);
extern int yylex();
extern int yyparse();

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

%type <expr_val> expr value
%type <var> variable_declaration assignment
%type <varType> type

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

program:
    function
;

function:
    FUN MAIN LPAREN RPAREN LBRACE statement_list RBRACE
;

statement_list:
    statement_list statement
    | statement
;

statement:
	variable_declaration
    | assignment
	| print_statement
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
            } else if ($4 == REAL_TYPE) {
		        if ($6.is_real) {
		            var.value.rval = $6.value.realNum;
		        } else {
		            var.value.rval = $6.value.intNum;
		        }
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
            } else if (var->type == REAL_TYPE) {
		        if ($3.is_real) {
		            var->value.rval = $3.value.realNum;
		        } else {
		            var->value.rval = $3.value.intNum;
		        }
            }
        }
    }
    ;

print_statement:
    PRINT LPAREN expr RPAREN SEMICOLON 		{ 
    	if($3.is_real)
    		printf("%f", $3.value.realNum); 
    	else
    		printf("%d", $3.value.intNum); 
    }
    | PRINTLN LPAREN expr RPAREN SEMICOLON	{ 
    	if($3.is_real)
    		printf("%f\n", $3.value.realNum); 
    	else
    		printf("%d\n", $3.value.intNum); 
    }
;

type:
    INT { $$ = INT_TYPE; }
    | REAL { $$ = REAL_TYPE; }
    | REAL LBRACKET INT_CONST RBRACKET
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


