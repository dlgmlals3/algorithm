#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node(int num_) : num(num_), l(nullptr), r(nullptr) {}
    int num;
    struct Node *l;
    struct Node *r; 
};

Node* insert(Node *root, int data) {
    if (root == nullptr) {
        root = new Node(data);
    } else if (root->num > data) {
        root->l = insert(root->l, data);
    } else {
        root->r = insert(root->r, data);
    }
    return root;
}

void postOrder(Node* n) {
    if (n==nullptr) return;
    if (n->l != nullptr) postOrder(n->l);
    if (n->r != nullptr) postOrder(n->r);
    cout << n->num << '\n';    
}


int main(void) {
    int num;    
    Node *root = nullptr;
    while (cin >> num) {
        if (num == cin.eof()) break;
        root = insert(root, num);
    }
    postOrder(root);
    return 0;
}