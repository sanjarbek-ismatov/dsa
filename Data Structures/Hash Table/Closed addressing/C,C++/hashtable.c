#include<stdio.h>
#include "../../../Linked List/C,C++/linkedlist.h"
int hash(char* string, int size_of_table){
    int i = 0;
    int hashed = 0;
    while(string[i] != '\0'){
        hashed += (int)string[i++];
    }
    return hashed % size_of_table;
}
char** hash_table_init(int size){
    char** array = (char**)malloc(256 * size);
    return array;
}
void insert(char* item, char** table, int table_size){
    int hashed = hash(item, table_size);
    // Conditionals should be written
      printf("%s\n", table[hashed]);
    table[hashed] = item;
  
}
int main(){
    // LinkedList list;
    // constructor(&list);
    // prepend(&list, 1);
    // prepend(&list, 2);
    // display(&list);
    char** table = hash_table_init(10);
    insert("Sanjarbek", table, 10);
    return 0;
}