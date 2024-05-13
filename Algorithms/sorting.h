#include<stdio.h>
#include"./utils.h"

/**
 * Selection sort Algorithm
*/
int* selection_sort(int given_arr[], int length);
/**
 * Test usage
int main(){
    int unsorted_arr[] = {2, 4, 1, 5, 3, 8, 2, 9, 0, 4};
    int length_of_arr = length(sizeof(unsorted_arr));
    int* result = selection_sort(unsorted_arr, length_of_arr); 
    print_arr(result, length_of_arr);
    return 0;
}
*/
int* selection_sort(int given_arr[], int length){
    int* arr = given_arr;
    int curr = arr[0];
    for(int i = 0; i < length; i++){
        int min = find_min(given_arr, length, i, length);
        curr = arr[i];
        arr[i] = arr[min];
        arr[min] = curr;
    }
    return arr;
}


