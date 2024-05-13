#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int length(int size){
    return size / sizeof(int);
}

int find_min(int arr[], int length, int start, int end){
    int min = start;
    for(int i = start + 1; i < length; i++){
        if(arr[min] > arr[i]){
            min = i;
        }
    }
    return min;
}

void print_arr(int arr[], int length){
    char result[9 * length];
    result[0] = '\0';
    strcat(result, "{");
    for(int i = 0; i < length - 1; i++){
        char temp[5];
        sprintf(temp, "%d, ", arr[i]);
        strcat(result, temp);
    }
    char final[3];
    sprintf(final, "%d", arr[length - 1]);
    strcat(result, final);
    result[strlen(result)] = '}';
    printf("%s\n", result);
}

int* slice(int arr[], int start, int end){
    int* temp = (int*)malloc((end - start + 1) * sizeof(int));
    for(int i = start; i < end; i++){
        temp[i] = arr[i];
    }
    return temp;
}



int sum(int* arr, int size){
   if(size == 0) return 0;
   return arr[size - 1] + sum(arr, size - 1); 
}

int sum_dq(int* arr, int start, int end){
    if(start > end) return 0;
    if(start == end) return arr[start];
    
    int middle = (start + end) / 2;
    int left_sum = sum_dq(arr, start, middle);
    int right_sum = sum_dq(arr, middle + 1, end);

    return left_sum + right_sum;
}