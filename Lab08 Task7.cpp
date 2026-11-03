#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> h;

    void heapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (h[i] < h[p]) {
                int t = h[i];
                h[i] = h[p];
                h[p] = t;
                i = p;
            }
            else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        int n = h.size();
        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int s = i;
            if (l < n && h[l] < h[s]) {
                s = l;
            }
            if (r < n && h[r] < h[s]) {
                s = r;
            }
            if (s == i) {
                break;
            }
            int t = h[i];
            h[i] = h[s];
            h[s] = t;
            i = s;
        }
    }

public:
    void insert(int u) {
        h.push_back(u);
        heapifyUp(h.size() - 1);
    }

    int extractMin() {
        if (h.empty()) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        int mn = h[0];
        h[0] = h[h.size() - 1];
        h.pop_back();
        if (!h.empty()) {
            heapifyDown(0);
        }
        return mn;
    }

    void display() {
        for (int i = 0; i < h.size(); i++) {
            cout << h[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap m;
    m.insert(35);
    m.insert(12);
    m.insert(25);
    m.insert(8);
    m.insert(40);
    m.insert(5);

    cout << "Heap: ";
    m.display();

    cout << "Removed: " << m.extractMin() << endl;

    cout << "Heap after removal: ";
    m.display();

    return 0;
}
