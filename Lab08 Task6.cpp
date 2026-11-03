#include <iostream>
using namespace std;

class CompleteBinaryTree {
    int tree[100];
    int count;

public:
    CompleteBinaryTree() {
        count = 0;
    }

    // level-order insertion
    void insert(int v) {
        if (count == 100) {
            cout << "Tree is full" << endl;
            return;
        }
        tree[count] = v;
        count++;
    }

    int getCount() {
        return count;
    }

    // left child = 2i+1, right child = 2i+2
    void preorder(int i) {
        if (i >= count) {
            return;
        }
        cout << tree[i] << " ";
        preorder(2 * i + 1);
        preorder(2 * i + 2);
    }

    void inorder(int i) {
        if (i >= count) {
            return;
        }
        inorder(2 * i + 1);
        cout << tree[i] << " ";
        inorder(2 * i + 2);
    }

    void postorder(int i) {
        if (i >= count) {
            return;
        }
        postorder(2 * i + 1);
        postorder(2 * i + 2);
        cout << tree[i] << " ";
    }
};

int main() {
    CompleteBinaryTree t;
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(60);

    cout << "Preorder : ";
    t.preorder(0);
    cout << endl;

    cout << "Inorder  : ";
    t.inorder(0);
    cout << endl;

    cout << "Postorder: ";
    t.postorder(0);
    cout << endl;

    return 0;
}
