#include <iostream>
using namespace std;

class Node {
public:
    char d;
    Node* l;
    Node* r;

    Node(char x) {
        d = x;
        l = NULL;
        r = NULL;
    }
};

class ExpTree {
public:
    Node* root;

    ExpTree() {
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

    // brackets are printed only for operator nodes (nodes having children)
    void in(Node* t) {
        if (t == NULL) {
            return;
        }
        if (t->l != NULL) {
            cout << "( ";
        }
        in(t->l);
        cout << t->d << " ";
        in(t->r);
        if (t->r != NULL) {
            cout << ") ";
        }
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
    // (A + B) * (C - D)
    ExpTree t;
    t.root = new Node('*');
    t.root->l = new Node('+');
    t.root->r = new Node('-');
    t.root->l->l = new Node('A');
    t.root->l->r = new Node('B');
    t.root->r->l = new Node('C');
    t.root->r->r = new Node('D');

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
