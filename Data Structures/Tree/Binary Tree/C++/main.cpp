#include <iostream>
#include <stack>
#include <utility>
using namespace std;

class Node{
public:
    string data;
    Node* left{};
    Node* right{};
    explicit Node(string data){
        this -> data = move(data);
    }
};
void deepTraverser(Node* root){
    stack<Node*> nodes;
    nodes.push(root);
    while(nodes.size() > 0){
        Node* current = nodes.top();
        cout << current -> data << endl;
        nodes.pop();
        if(current -> right) nodes.push(current -> right);
        if(current -> left) nodes.push(current -> left);
    }

}
int main(){
    Node* a = new Node("a");
    Node* b = new Node("b");
    Node* c = new Node("c");
    Node* d = new Node("d");
    Node* e = new Node("e");
    Node* f = new Node("f");
    a -> left = b;
    a -> right = c;
    b -> left = d;
    b -> right = e;
    c -> left = f;
    deepTraverser(a);
    return 0;
}