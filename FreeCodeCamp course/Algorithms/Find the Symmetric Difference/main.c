#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
bool includes(const int*arr, int item){
    const size_t length = sizeof(*arr) / sizeof(int);
    for(int i = 0; i < length; i++){
        if(arr[i] == item) return true;
    }
    return false;
}
void iterator(int* index, const int* arr1, const int * arr2, int* result){
    const size_t length = sizeof(*arr1) / sizeof(int);
    for(int i = 0; i < length; i++){
        int current = arr1[i];
        if(!(includes(arr2, current) && includes(result, current))){
            result[*index] = current;
            (*index)++;
        }
    }
}
void print(int length,const int* array){
    char* result_string = "[";
    for(int i = 0; i < length; ++i){
        char * tmp = "";
        sprintf(tmp, "%d, ", array[i]);
        strcpy(result_string, tmp);
    }
    strcpy(result_string, "]");
    printf("%s", result_string);
}
int* sym_difference(const int * arr1, const int * arr2){
    int* result = (int*)malloc(10 * sizeof(int));
    int index = 0;
    iterator(&index, arr1, arr2, result);
    iterator(&index, arr2, arr1, result);
    return result;
}
int* sym(int length, int * arrays, ...){
    int* result = malloc(length);
    va_list args;
    va_start(args, arrays);
    for(int i = 0;  i < arrays; ++i){
        int* array = va_arg(args, int*);
        if(length == 0){
            result = array;
        }
        result = sym_difference(result, array);
    }
    va_end(args);
    return result;
}
int main(){
    int array1[] = {1, 2, 3};
    int array2[] = {5, 2, 1, 4};
    int length = (sizeof(array1) + sizeof(array2)) / sizeof(int);
    int* result = sym(length,array1,array2);
    print(length, result);
    free(result);
    return 0;
}