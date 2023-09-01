#include <stdio.h>
struct Stack{
    int size;
    int array[];
};
void push(struct Stack* stack){
    sizeof((*stack).array[0]);
}
int main(){
    struct Stack stack;
    stack.array[0] = 0;
    push(&stack);
    return 0;
}