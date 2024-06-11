#include "symbolTable.h"

static SymbolTableNode *symbol_table = NULL;

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

void printVariableData(variable* var) {
    if(!var) return;

    cerr << "print var: " << var->name << endl;
    cerr << "\tvar_type: " << var->type << endl;
    cerr << "\tarrayLength: " << var->arrayLength << endl;
    cerr << "\tvalue: " << endl;
    cerr << "\t\tival: " << var->value.ival << endl;
    cerr << "\t\trval: " << var->value.rval << endl;
    
    cerr << "\t\tintArr: {";
    for(int i = 0; i < var->arrayLength; i++) {
        cerr << var->value.intArr << " ";
    }
    cerr << "}" << endl;

    cerr << "\t\trealArr {";
    for(int i = 0; i < var->arrayLength; i++) {
        cerr << var->value.realArr << " ";
    }
    cerr << "}" << endl;
    
}