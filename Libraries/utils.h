#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int length(int size){
    return size / sizeof(int);
}

int find_min(int arr[], int length, int start, int end){
    int min = 0;
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