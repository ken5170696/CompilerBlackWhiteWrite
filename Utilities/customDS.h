#ifndef CUSTOMDS_H
#define CUSTOMDS_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

using namespace std;

typedef enum { INT_TYPE , REAL_TYPE, INT_ARRAY_TYPE, REAL_ARRAY_TYPE, STRING_TYPE, FUNC_TYPE, VOID_TYPE } var_type;

typedef struct {
    var_type type;
    var_type returnType;
    union {
        int ival;
        float rval;
        int* intArr;
        float* realArr;
        char* str;
    } value;
    int arrayLength;
    char name[100];
} variable;

    
typedef struct {
    var_type type;
    var_type returnType;
    union {
        int intNum;
        float realNum;
        float* arrayNum;
        char* str;
    } value;
    vector<string>* exprStr;
    int arrayLength;
} exprVal;

typedef struct {
    int arrayLength;
    var_type varType;
} typeVal;


typedef struct {
    std::string str;
}StringWrapper;

bool is_var_type_array(var_type type);
bool is_var_type_real(var_type type);

char* getArrayString(int*, int len);
char* getArrayString(float*, int len);
char* getArrayString(char*);

string getExprStrStr(vector<string> exprStr);

variable exprValToVariable(exprVal expr);
exprVal variableToExprVal(variable var);

#endif
