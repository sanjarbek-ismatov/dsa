#include "../../Linked List/C,C++/main.cpp"
class Queue{
public:
    Queue(){
        this -> size = 0;
    }
//    initial state
    int size;
//    methods
    void enqueue(int data){
        list.prepend(data);
        this -> size++;
    }
    void dequeue(){
        list.pop();
        this -> size--;
    }
    int peek(){
        return list.peek();
    }
    void printQueue(){
        list.display();
    }
    bool is_empty(){
        return this -> size == 0;
    }
    int length(){
        return this -> size;
    }
private:
    LinkedList list;
};
int main(){
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.dequeue();
    queue.printQueue();
    return 0;
}