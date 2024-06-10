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
        int is_array;
        union {
            int intNum;
            float realNum;
            float* arrayNum;
        } value;
        int arrayLength;
    } expr_val;

    struct {
        int arrayLength;
        var_type varType;
    } type_val;
}


%token <intNum>   	INTEGER_CONST
%token <realNum> 	REAL_CONST
%token <str> 		IDENTIFIER
%token FUN MAIN VAR PRINT PRINTLN RET IF ELSE WHILE FOR TO INT REAL NEWLINE
%token LBRACE RBRACE LBRACKET RBRACKET LPAREN RPAREN SEMICOLON COMMA ASSIGN COLON

%type <str> function statement_list statement variable_declaration assignment print_statement
%type <expr_val> expr value value_list value_list_value
%type <type_val> type

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

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
            $$ = $1;
        }
	| print_statement {
            $$ = $1;
        }
;

variable_declaration:
    VAR IDENTIFIER COLON type SEMICOLON {
        variable var;
        strcpy(var.name, $2);
        var.type = $4.varType;
        var.arrayLength = $4.arrayLength;
        if (lookup_variable($2)) {
            yyerror("Variable already declared"); 
            YYABORT; 
        } else {
            insert_variable(var);
        }

        if($4.varType == INT_TYPE){
            $$ = (char*)malloc(strlen(var.name) + 11);
            sprintf($$, "int %s;\n", var.name);
        }else if($4.varType == REAL_TYPE){
            $$ = (char*)malloc(strlen(var.name) + 13);
            sprintf($$, "float %s;\n", var.name);
        }else if($4.varType == INT_ARRAY_TYPE){
            var.arrayLength = $4.arrayLength;
            var.value.intArr = (int *)malloc(sizeof(int) * var.arrayLength);

            // Return string
            int length = snprintf( NULL, 0, "%d", $4.arrayLength );
            $$ = (char*)malloc(length + strlen(var.name) + 14);
            sprintf($$, "int %s[%d];\n", var.name, $4.arrayLength);
        }else if($4.varType == REAL_ARRAY_TYPE){
            var.arrayLength = $4.arrayLength;
            var.value.realArr = (float *)malloc(sizeof(float) * var.arrayLength);
            
            // Return string
            int length = snprintf( NULL, 0, "%d", $4.arrayLength );
            $$ = (char*)malloc(length + strlen(var.name) + 16);
            sprintf($$, "float %s[%d];\n", var.name, $4.arrayLength);
        }
    }
    | VAR IDENTIFIER COLON type ASSIGN expr SEMICOLON {
        variable var;
        strcpy(var.name, $2);
        var.type = $4.varType;
        var.arrayLength = $4.arrayLength;
        if (lookup_variable($2)) {
            yyerror("Variable already declared"); 
            YYABORT; 
        } else {
            
            if($6.is_array){
                if((var.type == INT_TYPE || var.type == REAL_TYPE)) {
                    yyerror("You cannot asign a const to an array."); 
                    YYABORT; 
                }
                
                if(var.arrayLength < $6.arrayLength) {
                    yyerror("variable_declaration: Array out of bounds."); 
                    YYABORT; 
                }

                if (var.type == INT_ARRAY_TYPE) {
                    
                    var.value.intArr = (int *)malloc(sizeof(int) * var.arrayLength);
                    for(int i = 0; i < $6.arrayLength; i++){
                        var.value.intArr[i] = $6.value.arrayNum[i];
                    }

                    char* returnStr = (char*)malloc(5); // "{}\n"
                    strcpy(returnStr, "{");
                    int newLen = 5;
                    for(int i = 0; i < $6.arrayLength; i++){
                        int numLen = snprintf( NULL, 0, "%d", var.value.intArr[i] );
                        char* numStr = (char*)malloc(numLen);
                        sprintf( numStr, "%d", var.value.intArr[i] );
                        
                        newLen = newLen + 3 + numLen;
                        returnStr = (char*)(realloc(returnStr, newLen));
                        strcat(returnStr, numStr);
                        if(i == $6.arrayLength - 1)
                            break;
                        strcat(returnStr, ", ");
                    }
                    strcat(returnStr, "}\n");
                    // Return string
                    int length = snprintf( NULL, 0, "%d", $4.arrayLength );
                    $$ = (char*)malloc(length + strlen(var.name) + 16 + sizeof(returnStr));
                    sprintf($$, "int %s[%d] = %s", var.name, $4.arrayLength, returnStr);
                } else if (var.type == REAL_ARRAY_TYPE) {
                    var.value.realArr = (float *)malloc(sizeof(float) * var.arrayLength);
                    for(int i = 0; i < $6.arrayLength; i++){
                        var.value.realArr[i] = $6.value.arrayNum[i];
                    }


                    char* returnStr = (char*)malloc(5); // "{}\n"
                    strcpy(returnStr, "{");
                    int newLen = 5;
                    for(int i = 0; i < $6.arrayLength; i++){
                        int numLen = snprintf( NULL, 0, "%f", var.value.realArr[i] );
                        char* numStr = (char*)malloc(numLen);
                        sprintf( numStr, "%f", var.value.realArr[i] );
                        
                        newLen = newLen + 3 + numLen;
                        returnStr = (char*)(realloc(returnStr, newLen));
                        strcat(returnStr, numStr);
                        if(i == $6.arrayLength - 1)
                            break;
                        strcat(returnStr, ", ");
                    }
                    strcat(returnStr, "}\n");
                    // Return string
                    int length = snprintf( NULL, 0, "%d", $4.arrayLength );
                    $$ = (char*)malloc(length + strlen(var.name) + 18 + sizeof(returnStr));
                    sprintf($$, "float %s[%d] = %s", var.name, $4.arrayLength, returnStr);
                }
            }else {
                if (var.type == INT_TYPE) {
                    if ($6.is_real) {
                        var.value.ival = $6.value.realNum;
                    } else {
                        var.value.ival = $6.value.intNum;
                    }
                    int length = snprintf( NULL, 0, "%d", var.value.ival );
                    $$ = (char*)malloc(length + strlen(var.name) + 15);
                    sprintf($$, "int %s = %d;\n", var.name, var.value.ival);
                } else if (var.type == REAL_TYPE) {
                    if ($6.is_real) {
                        var.value.rval = $6.value.realNum;
                    } else {
                        var.value.rval = $6.value.intNum;
                    }
                    int length = snprintf( NULL, 0, "%f", var.value.rval );
                    $$ = (char*)malloc(length + strlen(var.name) + 17);
                    sprintf($$, "float %s = %f;\n", var.name, var.value.rval);
                }
            }
            insert_variable(var);
        }
    }
    ;

assignment:
    IDENTIFIER ASSIGN expr SEMICOLON {
        variable *var = lookup_variable($1);
        if (!var) {
            yyerror("Variable not declared"); 
            yyerror($1); 
            YYABORT; 
        } else {
            if($3.is_array){
                if((var->type == INT_TYPE || var->type == REAL_TYPE)) {
                    yyerror("You cannot asign a const to an array."); 
                    YYABORT; 
                }
                
                if(var->arrayLength < $3.arrayLength) {
                    yyerror("Array out of bounds."); 
                    YYABORT; 
                }

                // handle array's info
                for(int i = 0; i < $3.arrayLength; i++){
                    if (var->type == INT_ARRAY_TYPE) {
                        var->value.intArr[i] = $3.value.arrayNum[i];
                    } else if (var->type == REAL_ARRAY_TYPE) {
                        var->value.realArr[i] = $3.value.arrayNum[i];
                    }
                }
            }else {
                if((var->type == INT_ARRAY_TYPE || var->type == REAL_ARRAY_TYPE)) {
                    yyerror("You cannot asign an array to a const variable."); 
                    YYABORT; 
                }

                if (var->type == INT_TYPE) {
                    if ($3.is_real) {
                        var->value.ival = $3.value.realNum;
                    } else {
                        var->value.ival = $3.value.intNum;
                    }
                    int length = snprintf( NULL, 0, "%d", var->value.ival );
                    $$ = (char*)malloc(length + strlen(var->name) + 11);
                    sprintf($$, "%s = %d;\n", var->name, var->value.ival);
                } else if (var->type == REAL_TYPE) {
                    if ($3.is_real) {
                        var->value.rval = $3.value.realNum;
                    } else {
                        var->value.rval = $3.value.intNum;
                    }
                    int length = snprintf( NULL, 0, "%f", var->value.rval );
                    $$ = (char*)malloc(length + strlen(var->name) + 11);
                    sprintf($$, "%s = %f;\n", var->name, var->value.rval);
                }
            }
        }
    }
    ;

print_statement:
    PRINT LPAREN expr RPAREN SEMICOLON 		{ 

        if($3.is_array){
            yyerror("Array cannot be print out"); 
            YYABORT; 
        }

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
        if($3.is_array){
            yyerror("Array cannot be print out"); 
            YYABORT; 
        }
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
    INT { $$.varType = INT_TYPE; }
    | REAL { $$.varType = REAL_TYPE; }
    | REAL LBRACKET INTEGER_CONST RBRACKET { $$.varType = REAL_ARRAY_TYPE; $$.arrayLength = $3; }
    | INT LBRACKET INTEGER_CONST RBRACKET { $$.varType = INT_ARRAY_TYPE; $$.arrayLength = $3; }
;

expr:
      value                 { $$ = $1; }
    | IDENTIFIER			{
								variable *var = lookup_variable($1);
								if (!var) {
									yyerror("Variable not declared");
                                    yyerror($1); 
                                    YYABORT; 
								} else {
									if (var->type == INT_TYPE) {
    									$$.is_real = 0;
    									$$.is_array = 0;
										$$.value.intNum = var->value.ival;
									} else if (var->type == REAL_TYPE) {
    									$$.is_real = 1;
    									$$.is_array = 0;
										$$.value.realNum = var->value.rval;
									} else if (var->type == INT_ARRAY_TYPE) {
    									$$.is_real = 0;
    									$$.is_array = 1;
                                        $$.arrayLength = var->arrayLength;
                                        $$.value.arrayNum = (float*)malloc(sizeof(var->value.intArr));
                                        for(int i = 0; i < var->arrayLength; i++)
                                            $$.value.arrayNum[i] = var->value.intArr[i];
									} else if (var->type == REAL_ARRAY_TYPE) {
    									$$.is_real = 1;
    									$$.is_array = 1;
                                        $$.arrayLength = var->arrayLength;
                                        $$.value.arrayNum = (float*)malloc(sizeof(var->value.realArr));
                                        for(int i = 0; i < var->arrayLength; i++)
                                            $$.value.arrayNum[i] = var->value.realArr[i];
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
			if($2.is_real && !$2.is_array){
				$$.value.realNum = -$2.value.realNum;
                $$.is_real = $2.is_real;
                $$.is_array = $2.is_array;
            }
			else{
				$$.value.intNum = -$2.value.intNum;
                $$.is_real = $2.is_real;
                $$.is_array = $2.is_array;
            }
		}
    | LPAREN expr RPAREN          
		{ 
			if($2.is_real)
				$$.value.realNum = $2.value.realNum;
			else
				$$.value.intNum = $2.value.intNum;
		}
    | LBRACE value_list RBRACE {
        $$ = $2; 
    }
    ;

value:
      REAL_CONST                 { $$.value.realNum = $1; $$.is_real = 1; $$.is_array = 0;}
    | INTEGER_CONST               { $$.value.intNum = (float)$1;  $$.is_real = 0; $$.is_array = 0;}
    ;

value_list: 
    value_list COMMA value_list_value {
            const int len = $1.arrayLength + 1;
            float* fPtr = (float *)(realloc($1.value.arrayNum, (len) * sizeof(float)));
            $$.value.arrayNum = fPtr;
            $$.value.arrayNum[len - 1] = $3.is_real ? $3.value.realNum : $3.value.intNum;
            $$.arrayLength = len;
            $$.is_array = 1;
        }
    | value_list_value {
            $$.value.arrayNum = (float *)malloc(sizeof(float));
            
            $$.value.arrayNum[0] = $1.is_real ? $1.value.realNum : $1.value.intNum;
            $$.arrayLength = 1;
            $$.is_array = 1;
        }
    ;


value_list_value:
      value                 { $$ = $1; }
    | '-' value_list_value %prec UMINUS          
		{ 
			if($2.is_real && !$2.is_array){
				$$.value.realNum = -$2.value.realNum;
                $$.is_real = $2.is_real;
                $$.is_array = $2.is_array;
            }
			else{
				$$.value.intNum = -$2.value.intNum;
                $$.is_real = $2.is_real;
                $$.is_array = $2.is_array;
            }
		}
    | LPAREN value_list_value RPAREN          
		{ 
			if($2.is_real)
				$$.value.realNum = $2.value.realNum;
			else
				$$.value.intNum = $2.value.intNum;
		}
    ;
%%

void yyerror(const char *s) {
    cerr << s << endl;
}