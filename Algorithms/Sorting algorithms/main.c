#include<stdio.h>
int* selection_sort(int given_arr[], int length);
int main(){
    const unsorted_arr[] = {2, 4, 1, 5, 3};
    int* result = selection_sort(unsorted_arr, sizeof(unsorted_arr) / sizeof(unsorted_arr[0])); 
    return 0;
}
int* selection_sort(int given_arr[], int length){
    int* arr = given_arr;
    for(int i = 0; i < length; i++){
        int min = i;
        for(int j = i + 1; j < length; j++){
            if(arr[min] > arr[j]) {
                min = j;
            }
        }
        int curr = arr[i];
        arr[i] = arr[min];
        arr[min] = curr;
    }
    return arr;
}