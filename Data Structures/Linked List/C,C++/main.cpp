#include <iostream>
#include <string>
class Node{
public:
    int data;
    Node* next;
    explicit Node(int data){
        this -> data = data;
        this -> next = nullptr;
    };
};
class LinkedList{
private:
    Node* head{};
    Node* tail{};
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
    void prepend(int data){
        Node* node = new Node(data);
        node -> next = this -> head;
        this -> head = node;
        this -> size++;
    }
    int* pop(){
        if(this -> is_empty()) {
            return nullptr;
        }
        int* found = &this -> tail-> data;
        Node* current = this -> head;
        while(current->next && current -> next -> next != tail){
            current = current -> next;
        }
        current->next = nullptr;
        this ->tail = current;
        this -> size--;
        return found;
    }
    void reverse(){
        Node* prev = nullptr;
        Node* current = this -> head;
        Node* next = nullptr;
        while(current != nullptr){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        this -> head = prev;
    }
    void display(){
        std::string printable;
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
    auto* list = new LinkedList();
    list->prepend(10);
    list->prepend(20);
    list->prepend(30);
//    list -> pop();
    list -> reverse();
    list -> display();
    return 0;
}

