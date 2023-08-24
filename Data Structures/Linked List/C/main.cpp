#include <iostream>
#include <string>
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = nullptr;
    };
};
class LinkedList{
private:
    Node* head;
    Node* tail;
    int size = 0;
    bool is_empty() const{
        return this -> size == 0;
    }
public:
    void append(int data){
        Node* node = new Node(data);
        if(this -> is_empty()){
            this -> head = node;
            this -> tail = node;
        }else{
            this -> tail->next = node;
            this -> tail = this -> tail -> next;
        }
        this -> size++;
    }
    void display(){
        std::string printable = "";
        Node* current = this -> head;
        while(current){
            printable += std::to_string(current-> data);
            printable += " ";
            current = current->next;
        };
        std::cout << printable << std::endl;
    };
};
int main(){
    LinkedList* list = new LinkedList();
    list->append(10);
    list->append(20);
    list->append(30);
    list -> display();
    return 0;
}

