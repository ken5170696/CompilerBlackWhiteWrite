#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <iostream>
#include <stdio.h>

#include "customDS.h"

typedef struct SymbolTableNode {
    variable var;
    struct SymbolTableNode *next;
} SymbolTableNode;

void insert_variable(variable );
variable *lookup_variable(char*);
void printVariableData(variable*);

#endif
