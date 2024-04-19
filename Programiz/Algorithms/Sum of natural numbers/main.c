#include<stdio.h>
int calculate_sum_constant(int n){
    return (n * (n + 1)) / 2;
}
int main(){
    int res = calculate_sum_constant(100);
    printf("%d\n", res);
    return 0;
}