#include<string.h>
#include<stdio.h>
#include<math.h>
int sum(int s, int t){
    static int total = 0;
    return total += fabs(s - t);
}
int index_of(char* string, int size, char a){
    for(int i = 0; i < size; i++){
        if(string[i] == a) return i;
    }
    return -1;
}
int findPermutationDifference(char* s, char* t) {
    const int size = (int)strlen(s);
    printf("%d", size);
    for(int i = 0; i < size; i++){
        sum(i, index_of(t, size, s[i]));
    }
    return sum(0, 0);
}
int main(){
    const int res = findPermutationDifference("abc", "cab");
    printf("%d\n", res);
}