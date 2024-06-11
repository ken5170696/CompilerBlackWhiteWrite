#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <vector>
#include <iostream>
#include <stdio.h>

#include "customDS.h"

// symbol table structure
typedef struct SymbolTableNode {
    variable var;
    struct SymbolTableNode *next;
} SymbolTableNode;

typedef struct SymbolTable {
    SymbolTableNode *head;
} SymbolTable;

// str tab
char* generateTabByScopeTab(int depth);

// scoping 
int get_scope_count();
void push_scope();
void pop_scope();

// symbol table  
SymbolTable* get_current_table();
void insert_variable(variable );
variable *lookup_variable(char*);
variable *lookup_variable_with_scope(SymbolTable*, const char*);
void printVariableData(variable*);

#endif
