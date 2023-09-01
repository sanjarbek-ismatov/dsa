#include <iostream>
//#include <stack>
#include <vector>
class Stack{
public:
    void push(int data){
        stack.push_back(data);
    }
    int pop(){
        int last = stack.back();
        stack.pop_back();
        return last;
    }
    int top(){
        return stack.front();
    }
    int size(){
        return (int)stack.size();
    }
private:
    std::vector<int> stack;
    bool is_empty(){
        return stack.empty();
    }
};
int main(){
    auto stack = new Stack();
//    std::stack<int> stack;
    stack -> push(1);
    stack -> push(2);
    stack -> push(3);
    std::cout << stack -> size() << std::endl;
    return 0;
}