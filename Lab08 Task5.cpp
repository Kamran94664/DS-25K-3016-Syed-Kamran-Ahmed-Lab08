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

    // builds the tree recursively using user input
    Node* build() {
        int x;
        cin >> x;
        if (x == -1) {
            return NULL;
        }
        Node* n = new Node(x);
        cout << "Enter left child of " << x << " (-1 for none): ";
        n->l = build();
        cout << "Enter right child of " << x << " (-1 for none): ";
        n->r = build();
        return n;
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

    // free memory
    void del(Node* t) {
        if (t == NULL) {
            return;
        }
        del(t->l);
        del(t->r);
        delete t;
    }
};

int main() {
    Tree t;
    cout << "Enter root value (-1 for empty tree): ";
    t.root = t.build();

    if (t.root == NULL) {
        cout << "Tree is empty." << endl;
    }
    else {
        cout << "Preorder : ";
        t.pre(t.root);
        cout << endl;

        cout << "Inorder  : ";
        t.in(t.root);
        cout << endl;

        cout << "Postorder: ";
        t.post(t.root);
        cout << endl;
    }

    t.del(t.root);
    return 0;
}
