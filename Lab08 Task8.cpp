#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> h;

    void heapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (h[i] > h[p]) {
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
            int b = i;
            if (l < n && h[l] > h[b]) {
                b = l;
            }
            if (r < n && h[r] > h[b]) {
                b = r;
            }
            if (b == i) {
                break;
            }
            int t = h[i];
            h[i] = h[b];
            h[b] = t;
            i = b;
        }
    }

public:
    void insert(int p) {
        h.push_back(p);
        heapifyUp(h.size() - 1);
    }

    int extractMax() {
        if (h.empty()) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        int mx = h[0];
        h[0] = h[h.size() - 1];
        h.pop_back();
        if (!h.empty()) {
            heapifyDown(0);
        }
        return mx;
    }

    void display() {
        for (int i = 0; i < h.size(); i++) {
            cout << h[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap m;
    m.insert(40);
    m.insert(15);
    m.insert(30);
    m.insert(50);
    m.insert(10);
    m.insert(60);

    cout << "Heap: ";
    m.display();

    cout << "Removed: " << m.extractMax() << endl;

    cout << "Heap after removal: ";
    m.display();

    return 0;
}
