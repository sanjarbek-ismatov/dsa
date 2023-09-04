#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack{
    int size;
    int* array;
};
void push(struct Stack* stack, int data){
    int length = stack -> size;
    stack -> array[length] = data;
    stack -> size++;
}
int pop(struct Stack* stack){
    return stack -> array[stack -> size--];
}
void display(struct Stack stack){
    char* printable = (char *) malloc(stack.size);
    for(int i = 0; i < stack.size; i++){
        char* single_item = (char *) malloc(sizeof(char) * 12);
        sprintf(single_item, "%d " ,stack.array[i]);
        strcat(printable, single_item);
        free(single_item);
    }
    printf("%s\n", printable);
    free(printable);
}
int top(struct Stack stack){
    return stack.array[0];
}
int main(){
    struct Stack stack;
    stack.size = 0;
    stack.array = (int *)malloc(sizeof(int) * 100);
    push(&stack, 10);
    push(&stack, 20);
    display(stack);
    pop(&stack);

    free(stack.array);
    return 0;
}