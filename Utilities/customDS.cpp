#include "customDS.h"

bool is_var_type_array(var_type type){
    return (type == INT_ARRAY_TYPE || type == REAL_ARRAY_TYPE || type == STRING_TYPE);
}
bool is_var_type_real(var_type type){
    return (type == REAL_TYPE || type == REAL_ARRAY_TYPE);
}