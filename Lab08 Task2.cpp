#include <iostream>
using namespace std;

class Node {
public:
    int d;
    Node* l;
    Node* r;

    Node(int x) {
        d = x;
        l = NULL;
        r = NULL;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = NULL;
    }

    // Root - Left - Right
    void pre(Node* t) {
        if (t == NULL) {
            return;
        }
        cout << t->d << " ";
        pre(t->l);
        pre(t->r);
    }
};

int main() {
    Tree t;
    t.root = new Node(15);
    t.root->l = new Node(8);
    t.root->r = new Node(25);
    t.root->l->l = new Node(4);
    t.root->l->r = new Node(12);
    t.root->r->r = new Node(30);

    cout << "Preorder (Root-Left-Right): ";
    t.pre(t.root);
    cout << endl;

    return 0;
}
