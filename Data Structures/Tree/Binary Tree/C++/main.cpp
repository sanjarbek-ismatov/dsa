#include <iostream>
#include <stack>
#include <utility>
#include <vector>
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
//void deepFirstTraverser(Node* root){
//    stack<Node*> nodes;
//    vector<string> result;
//    nodes.push(root);
//    while(nodes.size() > 0){
//        Node* current = nodes.top();
//
//        result.push_back(current -> data);
//        nodes.pop();
//        if(current -> right) nodes.push(current -> right);
//        if(current -> left) nodes.push(current -> left);
//    }
//    for(const string& item: result){
//        cout << item << endl;
//    }
//}

vector<string> deepFirstTraverser(Node* root){
    vector<string> result;
    if(root == nullptr) return result;
    vector<string> leftNodes = deepFirstTraverser(root->left);
    vector<string> rightNodes = deepFirstTraverser(root->right);
    result.push_back(root -> data);
    for(const string& node: leftNodes){
        result.push_back(node);
    }
    for(const string& node: rightNodes){
        result.push_back(node);
    }
    return result;
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
    vector<string> result = deepFirstTraverser(a);
    for(const string& value: result){
        cout << value << endl;
    }
    return 0;
}