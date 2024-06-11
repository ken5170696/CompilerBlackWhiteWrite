%{
#include "main.h"
#include "./Utilities/customDS.h"
#include "./Utilities/symbolTable.h"

void yyerror(const char *s);
extern int yylex();
extern int yyparse();
%}

%union {
    int     intNum;
    float   realNum;
    StringWrapper* cppStr;
    variable var;
    var_type varType;
    exprVal expr_val;
    typeVal type_val;
}

%token              FUN MAIN VAR PRINT PRINTLN RET IF ELSE WHILE FOR TO INT REAL NEWLINE
%token              LBRACE RBRACE LBRACKET RBRACKET LPAREN RPAREN SEMICOLON COMMA ASSIGN COLON
%token <intNum>   	INTEGER_CONST
%token <realNum> 	REAL_CONST
%token <cppStr> 	IDENTIFIER STRING_CONST

%type <cppStr>      function block statement_list statement print_statement variable_declaration assignment
%type <expr_val>    expr value value_list value_list_value
%type <type_val>    type

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%nonassoc PAREN

%%

program:
    function {
        cout << "#include <stdio.h>\n\n" << $1->str << endl;
    }
;

function:
    FUN MAIN LPAREN RPAREN block {
        $$ = new StringWrapper();
        string mainStr = "int main() ";

        $$->str = mainStr + $5->str;
    }
    | FUN MAIN LPAREN RPAREN COLON type block {
        int scopeCount = get_scope_count();
        char* tabStr = generateTabByScopeTab(scopeCount);

        $$ = new StringWrapper();
        $$->str += tabStr;
        $$->str += $1->str;
    }
;
block: 
    LBRACE { push_scope(); } statement_list RBRACE {
        pop_scope(); 
        int scopeCount = get_scope_count();
        char* tabStr = generateTabByScopeTab(scopeCount);

        $$ = new StringWrapper();
        string statement_listStr = $3->str;
        $$->str += "\n";
        $$->str += tabStr;
        $$->str += "{\n";
        $$->str += statement_listStr;
        $$->str += tabStr;
        $$->str += "}\n";
    }
;
statement_list:
    statement_list statement{
        int scopeCount = get_scope_count();
        char* tabStr = generateTabByScopeTab(scopeCount);
        
        $$ = new StringWrapper();
        $$->str += $1->str;
        $$->str += tabStr;
        $$->str += $2->str;
    }
    | statement {
        int scopeCount = get_scope_count();
        char* tabStr = generateTabByScopeTab(scopeCount);

        $$ = new StringWrapper();
        $$->str += tabStr;
        $$->str += $1->str;
    }
;

statement:
	variable_declaration {
        $$ = new StringWrapper();
        $$->str = $1->str;
    }
    | assignment {
        $$ = new StringWrapper();
        $$->str = $1->str;
    }
	| print_statement {
        $$ = new StringWrapper();
        $$->str = $1->str;
    }
    | block {
            $$ = new StringWrapper();
            $$->str = $1->str;
    }
;

variable_declaration:
    VAR IDENTIFIER COLON type SEMICOLON {
        $$ = new StringWrapper();

        variable var;
        strcpy(var.name, $2->str.c_str());
        var.type = $4.varType;
        var.arrayLength = $4.arrayLength;
        if (lookup_variable_with_scope(get_current_table(), $2->str.c_str())) {
            yyerror("ERROR: duplicate declaration"); 
            YYABORT; 
        } else {
            insert_variable(var);
        }

        if($4.varType == INT_TYPE){
            stringstream ss;
            ss << "int " << var.name << ";\n";
            $$->str = ss.str();
        }else if($4.varType == REAL_TYPE){
            stringstream ss;
            ss << "float " << var.name << ";\n";
            $$->str = ss.str();
        }else if($4.varType == INT_ARRAY_TYPE){
            var.arrayLength = $4.arrayLength;
            var.value.intArr = (int *)malloc(sizeof(int) * var.arrayLength);

            // Return string
            stringstream ss;
            ss << "int " << var.name << "[" << $4.arrayLength << "];\n";
            $$->str = ss.str();

        }else if($4.varType == REAL_ARRAY_TYPE){
            var.arrayLength = $4.arrayLength;
            var.value.realArr = (float *)malloc(sizeof(float) * var.arrayLength);
            
            // Return string
            stringstream ss;
            ss << "int " << var.name << "[" << $4.arrayLength << "];\n";
            $$->str = ss.str();
        }
    }
    | VAR IDENTIFIER COLON type ASSIGN expr SEMICOLON {
        $$ = new StringWrapper();

        variable var;
        strcpy(var.name, $2->str.c_str());
        var.type = $4.varType;
        var.arrayLength = $4.arrayLength;
        if (lookup_variable_with_scope(get_current_table(), $2->str.c_str())) {
            yyerror("ERROR: duplicate declaration"); 
            YYABORT; 
        } else {
            
            if(is_var_type_array($6.type)){
                if((var.type == INT_TYPE || var.type == REAL_TYPE)) {
                    yyerror("ERROR: You cannot asign a const to an array."); 
                    YYABORT; 
                }
                
                if(var.arrayLength < $6.arrayLength) {
                    yyerror("ERROR: Array out of bounds."); 
                    YYABORT; 
                }
                if (var.type == INT_ARRAY_TYPE) {
                    var.value.intArr = (int *)malloc(sizeof(int) * var.arrayLength);
                    for(int i = 0; i < $6.arrayLength; i++){
                        var.value.intArr[i] = $6.value.arrayNum[i];
                    }

                    char* returnStr = getArrayString(var.value.intArr, var.arrayLength);

                    // Return string
                    stringstream ss;
                    ss << "int " << var.name << "[" << $4.arrayLength << "] = " << returnStr << ";\n";
                    $$->str = ss.str();
                } 
                else if (var.type == REAL_ARRAY_TYPE) {
                    var.value.realArr = (float *)malloc(sizeof(float) * var.arrayLength);
                    for(int i = 0; i < $6.arrayLength; i++){
                        var.value.realArr[i] = $6.value.arrayNum[i];
                    }

                    char* returnStr = getArrayString(var.value.realArr, var.arrayLength);

                    // Return string
                    stringstream ss;
                    ss << "float " << var.name << "[" << $4.arrayLength << "] = " << returnStr << ";\n";
                    $$->str = ss.str();
                }
            }else {
                if (var.type == INT_TYPE) {
                    if (is_var_type_real($6.type)) {
                        var.value.ival = $6.value.realNum;
                    } else {
                        var.value.ival = $6.value.intNum;
                    }

                    // Return string
                    stringstream ss;
                    ss << "int " << var.name << " = "<<var.value.ival<<";\n";
                    $$->str = ss.str();
                } else if (var.type == REAL_TYPE) {
                    if (is_var_type_real($6.type)) {
                        var.value.rval = $6.value.realNum;
                    } else {
                        var.value.rval = $6.value.intNum;
                    }
                    // Return string
                    stringstream ss;
                    ss << "float " << var.name << " = "<<var.value.rval<<";\n";
                    $$->str = ss.str();
                }
            }
            insert_variable(var);
        }
    }
;

assignment:
    IDENTIFIER ASSIGN expr SEMICOLON {
        $$ = new StringWrapper();

        variable *var = lookup_variable_with_scope(get_current_table(), $1->str.c_str());
        if (!var) {
            yyerror("Variable not declared"); 
            yyerror($1->str.c_str()); 
            YYABORT; 
        } else {
            if(is_var_type_array($3.type)){
                yyerror("Error: assigning to an array from an initializer list"); 
                YYABORT; 

                // if((var->type == INT_TYPE || var->type == REAL_TYPE)) {
                //     yyerror("Error: You cannot asign a const to an array."); 
                //     YYABORT; 
                // }
                
                // if(var->arrayLength < $3.arrayLength) {
                //     yyerror("Error: Array out of bounds."); 
                //     YYABORT; 
                // }

                // if (var->type == INT_ARRAY_TYPE) {
                //     var->value.intArr = (int *)malloc(sizeof(int) * var->arrayLength);
                //     for(int i = 0; i < $3.arrayLength; i++){
                //         var->value.intArr[i] = $3.value.arrayNum[i];
                //     }

                //     char* returnStr = getArrayString(var->value.intArr, var->arrayLength);
                //     // Return string
                //     $$ = (char*)malloc(sizeof(var->name) + 12 + sizeof(returnStr));
                //     sprintf($$, "%s = %s;\n", var->name, returnStr);
                // } else if (var->type == REAL_ARRAY_TYPE) {

                //     var->value.realArr = (float *)malloc(sizeof(float) * var->arrayLength);
                //     for(int i = 0; i < $3.arrayLength; i++){
                //         var->value.realArr[i] = $3.value.arrayNum[i];
                //     }

                //     char* returnStr = getArrayString(var->value.realArr, var->arrayLength);
                //     // Return string
                //     $$ = (char*)malloc(sizeof(var->name) + 12 + sizeof(returnStr));
                //     sprintf($$, "%s = %s;\n", var->name, returnStr);
                // }
            }else {
                if((var->type == INT_ARRAY_TYPE || var->type == REAL_ARRAY_TYPE)) {
                    yyerror("You cannot asign an array to a const variable."); 
                    YYABORT; 
                }

                if (var->type == INT_TYPE) {
                    if (is_var_type_real($3.type)) {
                        var->value.ival = $3.value.realNum;
                    } else {
                        var->value.ival = $3.value.intNum;
                    }
                    stringstream ss;
                    ss << var->name << " = " << var->value.ival << ";\n";
                    $$->str = ss.str();

                } else if (var->type == REAL_TYPE) {
                    if (is_var_type_real($3.type)) {
                        var->value.rval = $3.value.realNum;
                    } else {
                        var->value.rval = $3.value.intNum;
                    }

                    stringstream ss;
                    ss << var->name << " = " << var->value.rval << ";\n";
                    $$->str = ss.str();
                }
            }
        }
    }
;

print_statement:
    PRINT LPAREN expr RPAREN SEMICOLON 		{ 
        $$ = new StringWrapper();

    	if($3.type == INT_TYPE){
            stringstream ss;
            ss << "printf(\"" << $3.value.intNum << "\");\n";
            $$->str = ss.str();
        }
    	else if($3.type == REAL_TYPE){ 
            stringstream ss;
            ss << "printf(\"" << $3.value.realNum << "\");\n";
            $$->str = ss.str();
        } 
        else if(is_var_type_array($3.type)){
            char* arrayStr;
            switch($3.type){
            case INT_ARRAY_TYPE:
                arrayStr = getArrayString($3.value.arrayNum, $3.arrayLength);
                break; 
            case REAL_ARRAY_TYPE:
                arrayStr = getArrayString($3.value.arrayNum, $3.arrayLength);
                break; 
            case STRING_TYPE:
                arrayStr = getArrayString($3.value.str);
                break; 
            }
            
            stringstream ss;
            ss << "printf(\"" << arrayStr << "\");\n";
            $$->str = ss.str();
        }
    }
    | PRINTLN LPAREN expr RPAREN SEMICOLON	{ 
        $$ = new StringWrapper();

    	if($3.type == INT_TYPE){
            stringstream ss;
            ss << "printf(\"" << $3.value.intNum << "\\n\");\n";
            $$->str = ss.str();
        }
    	else if($3.type == REAL_TYPE){ 
            stringstream ss;
            ss << "printf(\"" << $3.value.realNum << "\\n\");\n";
            $$->str = ss.str();
        } 
        else if(is_var_type_array($3.type)){
            char* arrayStr;
            switch($3.type){
            case INT_ARRAY_TYPE:
                arrayStr = getArrayString($3.value.arrayNum, $3.arrayLength);
                break; 
            case REAL_ARRAY_TYPE:
                arrayStr = getArrayString($3.value.arrayNum, $3.arrayLength);
                break; 
            case STRING_TYPE:
                arrayStr = getArrayString($3.value.str);
                break; 
            }
            
            stringstream ss;
            ss << "printf(\"" << arrayStr << "\\n\");\n";
            $$->str = ss.str();
        }
    }
;

type:
    INT { 
        $$.varType = INT_TYPE; 
    }
    | REAL { 
        $$.varType = REAL_TYPE; 
    }
    | REAL LBRACKET INTEGER_CONST RBRACKET { 
        $$.varType = REAL_ARRAY_TYPE; 
        $$.arrayLength = $3; 
    }
    | INT LBRACKET INTEGER_CONST RBRACKET { 
        $$.varType = INT_ARRAY_TYPE; 
        $$.arrayLength = $3; 
    }
;

expr:
      value { 
        $$ = $1; 
    }
    | IDENTIFIER {
        variable *var = lookup_variable_with_scope(get_current_table(), $1->str.c_str());
        if (!var) {
            yyerror("ERROR: Variable not declared");
            yyerror($1->str.c_str()); 
            YYABORT; 
        } else {
            if (var->type == INT_TYPE) {
                $$.type = INT_TYPE;
                $$.value.intNum = var->value.ival;
            } else if (var->type == REAL_TYPE) {
                $$.type = REAL_TYPE;
                $$.value.realNum = var->value.rval;
            } else if (var->type == INT_ARRAY_TYPE) {
                $$.type = INT_ARRAY_TYPE;
                $$.arrayLength = var->arrayLength;
                $$.value.arrayNum = (float*)malloc(var->arrayLength * sizeof(float));
                for(int i = 0; i < $$.arrayLength; i++)
                    $$.value.arrayNum[i] = var->value.intArr[i];
            } else if (var->type == REAL_ARRAY_TYPE) {
                $$.type = REAL_ARRAY_TYPE;
                $$.arrayLength = var->arrayLength;
                $$.value.arrayNum = (float*)malloc(var->arrayLength * sizeof(float));
                for(int i = 0; i < $$.arrayLength; i++)
                    $$.value.arrayNum[i] = var->value.realArr[i];
            }
        }
    }
    | expr '+' expr {
        int isAllArray = is_var_type_array($1.type) + is_var_type_array($3.type);

        if(isAllArray == 1){
            yyerror("ERROR: expr type mismatch."); 
            YYABORT; 
        }

        if(isAllArray == 2) {
            
            if($1.arrayLength != $3.arrayLength){
                yyerror("ERROR: mismatched dimensions"); 
                YYABORT; 
            }
            int maxLen = MAX($1.arrayLength, $3.arrayLength);
            $$.value.arrayNum = (float *)(malloc((maxLen) * sizeof(float)));
            
            if(is_var_type_real($1.type) || is_var_type_real($3.type)){
                $$.type = REAL_ARRAY_TYPE;
            }else{
                $$.type = INT_ARRAY_TYPE;
            }

            for(int i = 0; i < maxLen; i++) {
                $$.value.arrayNum[i] =  (i < $1.arrayLength) ? $1.value.arrayNum[i] : 0;
                $$.value.arrayNum[i] += (i < $3.arrayLength) ? $3.value.arrayNum[i] : 0;
            }

        } else {
            float v1 = is_var_type_real($1.type) ? $1.value.realNum : $1.value.intNum;
            float v2 = is_var_type_real($3.type) ? $3.value.realNum : $3.value.intNum;

            if(is_var_type_real($1.type) || is_var_type_real($3.type)){
                $$.type = REAL_TYPE;
                $$.value.realNum = (v1 + v2);
            }else{
                $$.type = INT_TYPE;
                $$.value.intNum = (v1 + v2);
            }
        }
    }
    | expr '-' expr {
        int isAllArray = is_var_type_array($1.type) + is_var_type_array($3.type);

        if(isAllArray == 1){
            yyerror("ERROR: expr type mismatch."); 
            YYABORT; 
        }

        if(isAllArray == 2) {
            
            if($1.arrayLength != $3.arrayLength){
                yyerror("ERROR: mismatched dimensions"); 
                YYABORT; 
            }
            // vector math
            int maxLen = MAX($1.arrayLength, $3.arrayLength);
            $$.value.arrayNum = (float *)(malloc((maxLen) * sizeof(float)));
            
            if(is_var_type_real($1.type) || is_var_type_real($3.type)){
                $$.type = REAL_ARRAY_TYPE;
            }else{
                $$.type = INT_ARRAY_TYPE;
            }

            for(int i = 0; i < maxLen; i++) {
                $$.value.arrayNum[i] =  (i < $1.arrayLength) ? $1.value.arrayNum[i] : 0;
                $$.value.arrayNum[i] -= (i < $3.arrayLength) ? $3.value.arrayNum[i] : 0;
            }

        } else {
            // Non vector math
            float v1 = is_var_type_real($1.type) ? $1.value.realNum : $1.value.intNum;
            float v2 = is_var_type_real($3.type) ? $3.value.realNum : $3.value.intNum;

            if(is_var_type_real($1.type) || is_var_type_real($3.type)){
                $$.type = REAL_TYPE;
                $$.value.realNum = (v1 - v2);
            }else{
                $$.type = INT_TYPE;
                $$.value.intNum = (v1 - v2);
            }
        }
    }
    | expr '*' expr {
        int isAllArray = is_var_type_array($1.type) + is_var_type_array($3.type);

        if(isAllArray == 1){
            yyerror("ERROR: expr type mismatch."); 
            YYABORT; 
        }

        if(isAllArray == 2) {

            
            if($1.arrayLength != $3.arrayLength){
                yyerror("ERROR: mismatched dimensions"); 
                YYABORT; 
            }

            // vector math
            int maxLen = MAX($1.arrayLength, $3.arrayLength);

            // vector * vector = number
            float result = 0;
            for(int i = 0; i < maxLen; i++) {
                float v1 =  (i < $1.arrayLength) ? $1.value.arrayNum[i] : 0;
                float v2 =  (i < $3.arrayLength) ? $3.value.arrayNum[i] : 0;
                result += v1 * v2;
            }

            if(is_var_type_real($1.type) || is_var_type_real($3.type)){
                $$.type = REAL_TYPE;
                $$.value.realNum = result;
            }else{
                $$.type = INT_TYPE;
                $$.value.intNum = result;
            }

        } else {
            // Non vector math
            float v1 = is_var_type_real($1.type) ? $1.value.realNum : $1.value.intNum;
            float v2 = is_var_type_real($3.type) ? $3.value.realNum : $3.value.intNum;

            if(is_var_type_real($1.type) || is_var_type_real($3.type)){
                $$.type = REAL_TYPE;
                $$.value.realNum = (v1 * v2);
            }else{
                $$.type = INT_TYPE;
                $$.value.intNum = (v1 * v2);
            }
        }
    }
    | expr '/' expr {
        int isAllArray = is_var_type_array($1.type) + is_var_type_array($3.type);

        if(isAllArray == 1){
            yyerror("ERROR: expr type mismatch."); 
            YYABORT; 
        }

        if(isAllArray == 2) {
            
            if($1.arrayLength != $3.arrayLength){
                yyerror("ERROR: mismatched dimensions"); 
                YYABORT; 
            }
            // vector math
            int maxLen = MAX($1.arrayLength, $3.arrayLength);

            // vector * vector = number
            float result = 0;
            for(int i = 0; i < maxLen; i++) {
                float v1 =  (i < $1.arrayLength) ? $1.value.arrayNum[i] : 0;
                float v2 =  (i < $3.arrayLength) ? $3.value.arrayNum[i] : 0;
                if (v2 == 0.0) { 
                    yyerror("Error: divisor cannot be zero!"); 
                    YYABORT; 
                }
                result += v1 / v2;
            }

            if(is_var_type_real($1.type) || is_var_type_real($3.type)){
                $$.type = REAL_TYPE;
                $$.value.realNum = result;
            }else{
                $$.type = INT_TYPE;
                $$.value.intNum = result;
            }

        } else {
            float v1 = is_var_type_real($1.type) ? $1.value.realNum : $1.value.intNum;
            float v2 = is_var_type_real($3.type) ? $3.value.realNum : $3.value.intNum;
                
            if (v2 == 0.0) { 
                yyerror("Error: divisor cannot be zero!"); 
                YYABORT; 
            } else { 
                if(is_var_type_real($1.type) || is_var_type_real($3.type)){
                    $$.type = REAL_TYPE;
                    $$.value.realNum = (v1 / v2);
                }else{
                    $$.type = INT_TYPE;
                    $$.value.intNum = (v1 / v2);
                }
            } 
        }
    }
    | '-' expr %prec UMINUS { 
        if(is_var_type_real($2.type) && !is_var_type_array($2.type)){
            $$.value.realNum = -$2.value.realNum;
        }
        else{
            $$.value.intNum = -$2.value.intNum;
        }
        $$.type = $2.type;
    }
    | LPAREN expr RPAREN %prec PAREN {
        $$ = $2; 
    }
    | LBRACE value_list RBRACE {
        $$ = $2; 
    }
;

value:
    REAL_CONST { 
        $$.value.realNum = $1; 
        $$.type = REAL_TYPE;
    }
    | INTEGER_CONST { 
        $$.value.intNum = (float)$1;  
        $$.type = INT_TYPE;
    } 
    | STRING_CONST {  
        $$.value.str = (char *)malloc(strlen($1->str.c_str()));
        strcpy($$.value.str,($1->str.c_str() + 1)); 
        $$.value.str[strlen($$.value.str) - 1] = '\0';
        
        $$.type = STRING_TYPE;
    } 
;

value_list: 
    value_list COMMA value_list_value {
        const int len = $1.arrayLength + 1;
        float* fPtr = (float *)(realloc($1.value.arrayNum, (len) * sizeof(float)));
        $$.value.arrayNum = fPtr;
        $$.value.arrayNum[len - 1] = is_var_type_real($3.type) ? $3.value.realNum : $3.value.intNum;
        $$.arrayLength = len;
        $$.type = is_var_type_real($3.type) ? REAL_ARRAY_TYPE : INT_ARRAY_TYPE;
    }
    | value_list_value {
        $$.value.arrayNum = (float *)malloc(sizeof(float));
        
        $$.value.arrayNum[0] = is_var_type_real($1.type) ? $1.value.realNum : $1.value.intNum;
        $$.arrayLength = 1;
        $$.type = is_var_type_real($1.type) ? REAL_ARRAY_TYPE : INT_ARRAY_TYPE;
    }
;


value_list_value:
    value { 
        $$ = $1; 
    }
    | '-' value_list_value %prec UMINUS { 
        if(!is_var_type_array($2.type)){
            if(is_var_type_real($2.type)){
                $$.value.realNum = -$2.value.realNum;
            }
            else{
                $$.value.intNum = -$2.value.intNum;
            }
            $$.type = $2.type;
        }
    }
    | LPAREN value_list_value RPAREN { 
        if(is_var_type_real($2.type))
            $$.value.realNum = $2.value.realNum;
        else
            $$.value.intNum = $2.value.intNum;
        $$.type = $2.type;
    }
;
%%

void yyerror(const char *s) {
    cerr << s << endl;
}