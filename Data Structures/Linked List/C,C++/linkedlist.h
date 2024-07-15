#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    Node* next;
} Node;
typedef struct {
    Node* head;
    Node* tail;
   int size;
} LinkedList;
bool is_empty(const LinkedList list){
    return list.size == 0;
}
void append(LinkedList* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));
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
void prepend(LinkedList* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = list -> head;
    list -> head = node;
    list -> size++;
}
int* pop(LinkedList* list){
    if(is_empty(*list))return NULL;
    int* found = &list -> tail -> data;
    Node* current = list -> head;
    while (current->next && current -> next -> next != list -> tail){
        current = current -> next;
    }
    current->next = NULL;
    list -> tail = current;
    list -> size--;
    return found;
}
void reverse(LinkedList* list){
    Node* prev = NULL, *next = NULL;
    Node* current = list -> head;
    while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    list -> head = prev;
}
void display(const LinkedList* list){
    char* printable = (char*)malloc(list -> size * 2);
    Node* current = list -> head;
    char temp[15];
    while(current){
        sprintf(temp,"%d ", (current->data));
        strcat(printable, temp);
        current = current -> next;
    }
    printf("%s\n", printable);
    free(printable);
}

void constructor(LinkedList* list){
    list -> head = NULL;
    list -> tail = NULL;
    list -> size = 0;
}