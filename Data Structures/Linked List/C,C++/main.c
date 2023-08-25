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
void display(const struct LinkedList* list){
    char* printable = malloc(list -> size * 12);
    struct Node* current = list -> head;
    char temp[15];
    while(current){
        sprintf(temp,"%d ", (current->data));
        strcat(printable, temp);
        current = current -> next;
    }
    printf("%s", printable);
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
    append(&list, 10);
    append(&list, 20);
    append(&list, 30);
    display(&list);
    return 0;
}
