#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;


typedef enum { INT_TYPE, REAL_TYPE, ARRAY_TYPE } var_type;

typedef struct {
    var_type type;
    union {
        int ival;
        float rval;
    } value;
    char name[100];
} variable;

#endif
