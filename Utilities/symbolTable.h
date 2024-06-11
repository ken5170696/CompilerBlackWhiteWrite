#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <vector>
#include <iostream>
#include <stdio.h>

#include "customDS.h"

typedef struct SymbolTableNode {
    variable var;
    struct SymbolTableNode *next;
} SymbolTableNode;

typedef struct SymbolTable {
    SymbolTableNode *head;
} SymbolTable;

char* generateTabByScopeTab(int depth);

int get_scope_count();
SymbolTable* get_current_table();
void push_scope();
void pop_scope();

void insert_variable(variable );
variable *lookup_variable(char*);
variable *lookup_variable_with_scope(SymbolTable*, char*);
void printVariableData(variable*);

#endif
