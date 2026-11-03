#include <iostream>
using namespace std;

class HeapSort {
public:
    int a[9];
    int n;
    int sw;   // total swaps

    HeapSort(int x[], int size) {
        n = size;
        sw = 0;
        for (int i = 0; i < n; i++) {
            a[i] = x[i];
        }
    }

    void swp(int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        sw++;
    }

    void show() {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    // push a[i] down so the subtree becomes a max heap (heap size = sz)
    void heapify(int sz, int i) {
        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int b = i;
            if (l < sz && a[l] > a[b]) {
                b = l;
            }
            if (r < sz && a[r] > a[b]) {
                b = r;
            }
            if (b == i) {
                break;
            }
            swp(i, b);
            i = b;
        }
    }

    void sort() {
        // build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(n, i);
        }
        cout << "After building Max Heap: ";
        show();
        cout << endl;

        // extract max one by one
        for (int i = n - 1; i > 0; i--) {
            swp(0, i);        // move max to the end
            heapify(i, 0);    // fix the remaining heap
            cout << "After extraction " << (n - i) << ": ";
            show();
        }
    }
};

int main() {
    int x[9] = {42, 17, 63, 28, 51, 9, 36, 74, 23};
    HeapSort h(x, 9);

    cout << "Original array: ";
    h.show();

    h.sort();

    cout << endl;
    cout << "Sorted array: ";
    h.show();
    cout << "Total swaps: " << h.sw << endl;

    return 0;
}
