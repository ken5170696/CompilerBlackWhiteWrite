#ifndef CUSTOMDS_H
#define CUSTOMDS_H

#include <iostream>
#include <stdio.h>
#include <cstring>

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

using namespace std;

typedef enum { INT_TYPE , REAL_TYPE, INT_ARRAY_TYPE, REAL_ARRAY_TYPE } var_type;

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

    
typedef struct {
    int is_real;
    int is_array;
    union {
        int intNum;
        float realNum;
        float* arrayNum;
    } value;
    int arrayLength;
} exprVal;

typedef struct {
    int arrayLength;
    var_type varType;
} typeVal;

#endif
