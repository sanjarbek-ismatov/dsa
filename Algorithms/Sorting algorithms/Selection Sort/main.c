#include<stdio.h>
#include"../../../Libraries/utils.h"
int* selection_sort(int given_arr[], int length);
int main(){
    int unsorted_arr[] = {2, 4, 1, 5, 3};
    int length_of_arr = length(sizeof(unsorted_arr));
    int* result = selection_sort(unsorted_arr, length_of_arr); 
    print_arr(result, length_of_arr);
    return 0;
}
int* selection_sort(int given_arr[], int length){
    int* arr = given_arr;
    for(int i = 0; i < length; i++){
        int min = find_min(given_arr, length, i, length);
        printf("%d %d\n", arr[i], arr[min]);
        int curr = arr[i];
        arr[i] = arr[min];
        arr[min] = curr;
    }
    return arr;
}