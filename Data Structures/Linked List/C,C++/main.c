#include "linkedlist.h"

int main(){
    LinkedList list;
    constructor(&list);
    prepend(&list, 10);
    prepend(&list, 20);
    prepend(&list, 30);
//    pop(&list);
    reverse(&list);
    display(&list);
    return 0;
}
