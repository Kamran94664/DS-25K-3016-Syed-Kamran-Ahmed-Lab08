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

    void pre(Node* t) {
        if (t == NULL) {
            return;
        }
        cout << t->d << " ";
        pre(t->l);
        pre(t->r);
    }

    void in(Node* t) {
        if (t == NULL) {
            return;
        }
        in(t->l);
        cout << t->d << " ";
        in(t->r);
    }

    void post(Node* t) {
        if (t == NULL) {
            return;
        }
        post(t->l);
        post(t->r);
        cout << t->d << " ";
    }
};

int main() {
    Tree t;
    t.root = new Node(10);
    t.root->l = new Node(20);
    t.root->r = new Node(30);
    t.root->l->l = new Node(40);
    t.root->l->r = new Node(50);

    cout << "Preorder : ";
    t.pre(t.root);
    cout << endl;

    cout << "Inorder  : ";
    t.in(t.root);
    cout << endl;

    cout << "Postorder: ";
    t.post(t.root);
    cout << endl;

    return 0;
}
