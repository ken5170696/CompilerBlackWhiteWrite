#include "symbolTable.h"

static vector<SymbolTable*> scope_stack;

char* generateTabByScopeTab(int depth){
    char* tabStr = (char*)malloc(depth * 2 + 1);
    strcpy(tabStr, "");
    for(int i = 0; i < depth; i++){
        strcat(tabStr, "\t");
    }
    return tabStr;
}

int get_scope_count() {
    return scope_stack.size();
}

void push_scope() {
    SymbolTable *new_table = (SymbolTable *)malloc(sizeof(SymbolTable));
    new_table->head = NULL;
    scope_stack.push_back(new_table);
}

void pop_scope() {
    if (!scope_stack.empty()) {
        SymbolTable *top_table = scope_stack.back();
        scope_stack.pop_back();
        free(top_table);
    }
}

void insert_variable(variable var) {
    if (scope_stack.empty()) {
        push_scope();
    }
    SymbolTable *current_table = scope_stack.back();
    SymbolTableNode *new_node = (SymbolTableNode *)malloc(sizeof(SymbolTableNode));
    new_node->var = var;
    new_node->next = current_table->head;
    current_table->head = new_node;
}

variable *lookup_variable_with_scope(SymbolTable *current_table, char *name) {
    if(!current_table) return NULL;
    vector<SymbolTable*> temp_stack = scope_stack;
    SymbolTableNode *current_node = current_table->head;
    while (current_node != NULL) {
        if (strcmp(current_node->var.name, name) == 0) {
            return &current_node->var;
        }
        current_node = current_node->next;
    }
    return NULL;
}
SymbolTable* get_current_table(){
    vector<SymbolTable*> temp_stack = scope_stack;
    SymbolTable *current_table = temp_stack.back();
    return current_table;
}
variable *lookup_variable(char *name) {
    
    vector<SymbolTable*> temp_stack = scope_stack;
    while (!temp_stack.empty()) {
        SymbolTable *current_table = temp_stack.back();
        SymbolTableNode *current_node = current_table->head;
        while (current_node != NULL) {
            if (strcmp(current_node->var.name, name) == 0) {
                return &current_node->var;
            }
            current_node = current_node->next;
        }
        temp_stack.pop_back();
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
        cerr << var->value.intArr[i] << " ";
    }
    cerr << "}" << endl;

    cerr << "\t\trealArr {";
    for(int i = 0; i < var->arrayLength; i++) {
        cerr << var->value.realArr[i] << " ";
    }
    cerr << "}" << endl;
    
}