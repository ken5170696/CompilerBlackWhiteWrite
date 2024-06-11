#include "customDS.h"

bool is_var_type_array(var_type type){
    return (type == INT_ARRAY_TYPE || type == REAL_ARRAY_TYPE || type == STRING_TYPE);
}
bool is_var_type_real(var_type type){
    return (type == REAL_TYPE || type == REAL_ARRAY_TYPE);
}

char* getArrayString(int* intArray, int len) {
    char* returnStr = (char*)malloc(5); // "{}\n"
    strcpy(returnStr, "{");
    int newLen = 5;
    for(int i = 0; i < len; i++){
        int numLen = snprintf( NULL, 0, "%d", intArray[i] );
        char* numStr = (char*)malloc(numLen);
        sprintf( numStr, "%d", intArray[i] );
        
        newLen = newLen + 3 + numLen;
        returnStr = (char*)(realloc(returnStr, newLen));
        strcat(returnStr, numStr);

        if(i == len - 1)
            break;
        strcat(returnStr, ", ");
    }
    strcat(returnStr, "}");
    return returnStr;
}
char* getArrayString(float* floatArray, int len){
    char* returnStr = (char*)malloc(5); // "{}\n"
    strcpy(returnStr, "{");
    int newLen = 5;
    for(int i = 0; i < len; i++){
        int numLen = snprintf( NULL, 0, "%f", floatArray[i] );
        char* numStr = (char*)malloc(numLen);
        sprintf( numStr, "%f", floatArray[i] );
        
        newLen = newLen + 3 + numLen;
        returnStr = (char*)(realloc(returnStr, newLen));
        strcat(returnStr, numStr);

        if(i == len - 1)
            break;
        strcat(returnStr, ", ");
    }
    strcat(returnStr, "}");
    return returnStr;
}

char* getArrayString(char* charArray){
    char* returnStr = (char*)malloc(sizeof(charArray));
    strcpy(returnStr, charArray);
    return returnStr;
}

variable exprValToVariable(exprVal expr){
    variable var;

    var.type = expr.type;
    var.arrayLength = expr.arrayLength;
    switch(expr.type) {
        case INT_TYPE:
            var.value.ival = expr.value.intNum;
            break;
        case REAL_TYPE:
            var.value.rval = expr.value.realNum;
            break;
        case INT_ARRAY_TYPE:
            var.value.intArr = (int *)malloc(sizeof(int) * expr.arrayLength);
            for(int i = 0; i < var.arrayLength; i++){
                var.value.intArr[i] = expr.value.arrayNum[i];
            }
            break;
        case REAL_ARRAY_TYPE:
            var.value.realArr = (float *)malloc(sizeof(float) * expr.arrayLength);
            for(int i = 0; i < var.arrayLength; i++){
                var.value.realArr[i] = expr.value.arrayNum[i];
            }
            break;
        case STRING_TYPE:
            var.value.str = (char *)malloc(sizeof(expr.value.arrayNum));
            strcpy(var.value.str, expr.value.str);
            break;
    }
    return var;
}

exprVal variableToExprVal(variable var){
    exprVal expr;

    expr.type = var.type;
    expr.arrayLength = var.arrayLength;
    switch(expr.type) {
        case INT_TYPE:
            expr.value.intNum = var.value.ival;
            break;
        case REAL_TYPE:
            expr.value.realNum = var.value.rval;
            break;
        case INT_ARRAY_TYPE:
            expr.value.arrayNum = (float *)malloc(sizeof(float) * var.arrayLength);
            for(int i = 0; i < var.arrayLength; i++){
                expr.value.arrayNum[i] = var.value.intArr[i];
            }
            break;
        case REAL_ARRAY_TYPE:
            expr.value.arrayNum = (float *)malloc(sizeof(float) * var.arrayLength);
            for(int i = 0; i < var.arrayLength; i++){
                expr.value.arrayNum[i] = var.value.realArr[i];
            }
            break;
        case STRING_TYPE:
            expr.value.str = (char *)malloc(sizeof(var.value.str));
            strcpy(expr.value.str, var.value.str);
            break;
    }
    return expr;
}