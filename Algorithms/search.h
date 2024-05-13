/**
 * Binary search algorithm 
 * Time complexity: O(log n)
*/
int binary_search(int* arr, int size, int target){
    int left = 0;
    int right = size;
    int midd = 0;
    while(left < right){
        midd = (left + right) / 2;
        if(arr[midd] == target) return midd;
        else if(arr[midd] > target) right = midd - 1;
        else left = midd + 1;
    }
    return arr[midd] == target ? midd : -1;
}

/**
 * Binary search by recursion
 * Time complexity: O(log n)
*/
int binary_search_rec(int* arr, int target,  int left, int right){
    if(left > right) return -1;
    int midd = (left + right) / 2;
    if(arr[midd] == target) return midd;
    else if(arr[midd] > target) binary_search_rec(arr, target, left, midd - 1);
    else binary_search_rec(arr, target, midd + 1, right);
 }