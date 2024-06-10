#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

typedef enum { INT_TYPE, REAL_TYPE, INT_ARRAY_TYPE, REAL_ARRAY_TYPE } var_type;

typedef struct {
    var_type type;
    union {
        int ival;
        float rval;
        int* intArr;
        float* realArr;
    } value;
    int arrayLength;
    char name[100];
} variable;
/* 

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
*/
#endif
