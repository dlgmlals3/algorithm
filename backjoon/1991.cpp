#include <iostream>
#include <map>

using namespace std;

map<char, pair<char, char>> tree;

void preOrder(char first) {
    auto item = tree.find(first);
    if (item == tree.end()) {
        return;    
    }
    cout << item->first;
    preOrder(item->second.first);
    preOrder(item->second.second);
}

void infixOrder(char first) {
    auto item = tree.find(first);
    if (item == tree.end()) {
        return;    
    }
    infixOrder(item->second.first);
    cout << item->first;
    infixOrder(item->second.second);
}

void postOrder(char first) {
    auto item = tree.find(first);
    if (item == tree.end()) {
        return;    
    }
    postOrder(item->second.first);
    postOrder(item->second.second);
    cout << item->first;
}

int main(void) {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        char node, l, r;
        cin >> node >> l >> r;
        tree[node] = make_pair(l, r);
    }

    preOrder('A');
    cout << '\n';
    infixOrder('A');
    cout << '\n';
    postOrder('A');
    cout << '\n';
    return 0;
}