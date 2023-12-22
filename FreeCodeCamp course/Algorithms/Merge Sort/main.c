#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int * slice(const int * arr, int start, int end){
    int* result = (int *)malloc(sizeof arr);
    for(int i = 0; i < start - end; i++){
        result[i] = arr[i + start];
    }
    return result;
}
int * merge(const int * left, int left_size, const int * right, int right_size){
    int left_index = 0, right_index = 0, current_index = 0;
    int * result = (int * )malloc(sizeof(left) + sizeof(right));
    while(left_index < left_size && right_index < right_size){
        if(left[left_index] < right[right_index]){
            result[current_index] = left[left_index];
            left_index++;
        } else{
            result[current_index] = right[right_index];
            right_index++;
        }
        current_index++;
    }
    return result;
}
int * merge_sort(int * arr, int size){
    if(size <= 1) return arr;
    int mid = floor(size / 2);
    const int * left = merge_sort(slice(arr, 0, mid), mid + 1);
    const int * right = merge_sort(slice(arr, mid, size), size - mid - 1);
    return merge(left, mid + 1, right, size - mid - 1);
}

void print(const int * arr, int size){
    char * string = "[ ";
    for(int i = 0; i < size; i++){
        sprintf(string, ", %d", arr[i]);
    }
    strcpy(string, " ]");
    printf("%s", string);
}
int main(){
    int arr[] = {1, 4, 3, 2, 5};
    const int * sorted = merge_sort(arr, 5);
    print(sorted, 5);
    return 0;
}