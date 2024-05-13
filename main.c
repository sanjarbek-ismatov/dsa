#include"./Algorithms/utils.h"
#include"./Algorithms/search.h"
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // printf("%d\n", sum_dq(arr, 0, 3));
    printf("%d\n",binary_search_rec(arr, 5, 0, 4));
    return 0;
}