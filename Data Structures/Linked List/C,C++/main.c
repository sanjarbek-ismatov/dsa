#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};
struct LinkedList{
   struct Node* head;
   struct Node* tail;
   int size;
};
bool is_empty(const struct LinkedList list){
    return list.size == 0;
}
void append(struct LinkedList* list, int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = data;
    node -> next = NULL;
    if(is_empty(*list)){
        list -> head = node;
        list -> tail = node;
    }else{
        list -> tail -> next = node;
        list -> tail = node;
    }
    list -> size++;
}
void prepend(struct LinkedList* list, int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = data;
    node -> next = list -> head;
    list -> head = node;
    list -> size++;
}
void display(const struct LinkedList* list){
    char* printable = (char*)malloc(list -> size * 2);
    struct Node* current = list -> head;
    char temp[15];
    while(current){
        sprintf(temp,"%d ", (current->data));
        strcat(printable, temp);
        current = current -> next;
    }
    printf("%s\n", printable);
    free(printable);
}

void constructor(struct LinkedList* list){
    list -> head = NULL;
    list -> tail = NULL;
    list -> size = 0;
}
int main(){
    struct LinkedList list;
    constructor(&list);
    prepend(&list, 10);
    prepend(&list, 20);
    prepend(&list, 30);
    display(&list);
    return 0;
}
