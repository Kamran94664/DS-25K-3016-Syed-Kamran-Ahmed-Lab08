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

    // Left - Root - Right
    void in(Node* t) {
        if (t == NULL) {
            return;
        }
        in(t->l);
        cout << t->d << " ";
        in(t->r);
    }
};

int main() {
    Tree t;
    t.root = new Node(35);
    t.root->l = new Node(18);
    t.root->r = new Node(55);
    t.root->l->l = new Node(10);
    t.root->l->r = new Node(25);
    t.root->r->l = new Node(45);
    t.root->r->r = new Node(65);

    cout << "Inorder (Left-Root-Right): ";
    t.in(t.root);
    cout << endl;

    return 0;
}
