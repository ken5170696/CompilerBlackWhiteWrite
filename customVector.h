#ifndef CUSTOMVECTOR_H
#define CUSTOMVECTOR_H

#include <stdio.h>
#include <stdlib.h> // for memory allocation

void printArray(int* array, int len) { // e.g: result: {2, 5, 4}
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", array[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("}");
}
void printArray(float* array, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%f", array[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("}");
}
void printArray(int array, int len) {
    printf("%d", array);
}
void printArray(float array, int len) {
    printf("%f", array);
}

void printArrayln(int* array, int len) { // e.g: result: {2, 5, 4}
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", array[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
void printArrayln(float* array, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%f", array[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
void printArrayln(int array, int len) {
    printf("%d\n", array);
}
void printArrayln(float array, int len) {
    printf("%f\n", array);
}


float* addArray(float* array1, float* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for addition.\n");
        return NULL;
    }

    // Allocate memory for the result array
    float* result = (float*)malloc(len1 * sizeof(float));
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    // Perform element-wise addition
    for (int i = 0; i < len1; i++) {
        result[i] = array1[i] + array2[i];
    }

    return result;
}
float* subArray(float* array1, float* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for subtraction.\n");
        return NULL;
    }

    // Allocate memory for the result array
    float* result = (float*)malloc(len1 * sizeof(float));
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    // Perform element-wise subtraction
    for (int i = 0; i < len1; i++) {
        result[i] = array1[i] - array2[i];
    }

    return result;
}
float dotArray(float* array1, float* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for dot product calculation.\n");
        return 0.0;
    }

    // Calculate the dot product
    float dotProduct = 0.0;
    for (int i = 0; i < len1; i++) {
        dotProduct += array1[i] * array2[i];
    }

    return dotProduct;
}

float* addArray(float* array1, int* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for addition.\n");
        return NULL;
    }

    // Allocate memory for the result array
    float* result = (float*)malloc(len1 * sizeof(float));
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    // Perform element-wise addition
    for (int i = 0; i < len1; i++) {
        result[i] = array1[i] + array2[i];
    }

    return result;
}
float* subArray(float* array1, int* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for subtraction.\n");
        return NULL;
    }

    // Allocate memory for the result array
    float* result = (float*)malloc(len1 * sizeof(float));
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    // Perform element-wise subtraction
    for (int i = 0; i < len1; i++) {
        result[i] = array1[i] - array2[i];
    }

    return result;
}
float dotArray(float* array1, int* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for dot product calculation.\n");
        return 0.0;
    }

    // Calculate the dot product
    float dotProduct = 0.0;
    for (int i = 0; i < len1; i++) {
        dotProduct += array1[i] * array2[i];
    }

    return dotProduct;
}

float* addArray(int* array1, float* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for addition.\n");
        return NULL;
    }

    // Allocate memory for the result array
    float* result = (float*)malloc(len1 * sizeof(float));
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    // Perform element-wise addition
    for (int i = 0; i < len1; i++) {
        result[i] = array1[i] + array2[i];
    }

    return result;
}
float* subArray(int* array1, float* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for subtraction.\n");
        return NULL;
    }

    // Allocate memory for the result array
    float* result = (float*)malloc(len1 * sizeof(float));
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    // Perform element-wise subtraction
    for (int i = 0; i < len1; i++) {
        result[i] = array1[i] - array2[i];
    }

    return result;
}
float dotArray(int* array1, float* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for dot product calculation.\n");
        return 0.0;
    }

    // Calculate the dot product
    float dotProduct = 0.0;
    for (int i = 0; i < len1; i++) {
        dotProduct += array1[i] * array2[i];
    }

    return dotProduct;
}

int* addArray(int* array1, int* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for addition.\n");
        return NULL;
    }

    // Allocate memory for the result array
    int* result = (int*)malloc(len1 * sizeof(int));
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    // Perform element-wise addition
    for (int i = 0; i < len1; i++) {
        result[i] = array1[i] + array2[i];
    }

    return result;
}
int* subArray(int* array1, int* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for subtraction.\n");
        return NULL;
    }

    // Allocate memory for the result array
    int* result = (int*)malloc(len1 * sizeof(int));
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    // Perform element-wise subtraction
    for (int i = 0; i < len1; i++) {
        result[i] = array1[i] - array2[i];
    }

    return result;
}
int dotArray(int* array1, int* array2, int len1, int len2) {
    // Ensure both arrays are of the same length
    if (len1 != len2) {
        printf("Error: Arrays must have the same length for dot product calculation.\n");
        return 0.0;
    }

    // Calculate the dot product
    int dotProduct = 0.0;
    for (int i = 0; i < len1; i++) {
        dotProduct += array1[i] * array2[i];
    }

    return dotProduct;
}
#endif
