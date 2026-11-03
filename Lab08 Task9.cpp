#include <iostream>
#include <vector>
using namespace std;

class Req {
public:
    int id;
    int pr;   // smaller = more urgent
    int ord;  // arrival order (used to break ties)

    Req(int i, int p, int o) {
        id = i;
        pr = p;
        ord = o;
    }
};

class PQ {
    vector<Req> h;
    int cnt;

    // true if a is more urgent than b
    // same priority -> the one that arrived first wins (FIFO)
    bool better(Req a, Req b) {
        if (a.pr != b.pr) {
            return a.pr < b.pr;
        }
        return a.ord < b.ord;
    }

    void up(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (better(h[i], h[p])) {
                Req t = h[i];
                h[i] = h[p];
                h[p] = t;
                i = p;
            }
            else {
                break;
            }
        }
    }

    void down(int i) {
        int n = h.size();
        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int s = i;
            if (l < n && better(h[l], h[s])) {
                s = l;
            }
            if (r < n && better(h[r], h[s])) {
                s = r;
            }
            if (s == i) {
                break;
            }
            Req t = h[i];
            h[i] = h[s];
            h[s] = t;
            i = s;
        }
    }

public:
    PQ() {
        cnt = 0;
    }

    void insert(int id, int pr) {
        h.push_back(Req(id, pr, cnt));
        cnt++;
        up(h.size() - 1);
        cout << "Inserted -> ID: " << id << ", Priority: " << pr << endl;
    }

    void removeTop() {
        if (h.empty()) {
            cout << "No requests to remove" << endl;
            return;
        }
        Req t = h[0];
        h[0] = h[h.size() - 1];
        h.pop_back();
        if (!h.empty()) {
            down(0);
        }
        cout << "Removed  -> ID: " << t.id << ", Priority: " << t.pr << endl;
    }

    void peek() {
        if (h.empty()) {
            cout << "No requests in queue" << endl;
            return;
        }
        cout << "Next     -> ID: " << h[0].id << ", Priority: " << h[0].pr << endl;
    }

    void display() {
        cout << "Heap array: ";
        for (int i = 0; i < h.size(); i++) {
            cout << "(" << h[i].id << ",P" << h[i].pr << ") ";
        }
        cout << endl;
    }
};

int main() {
    PQ q;

    q.insert(101, 3);
    q.insert(102, 1);
    q.insert(103, 5);
    q.insert(104, 2);
    q.insert(105, 1);   // same priority as 102 -> 102 comes first
    q.insert(106, 4);
    q.display();

    cout << endl;
    q.peek();
    q.removeTop();
    q.peek();
    q.removeTop();

    cout << endl;
    q.insert(107, 1);
    q.display();
    q.peek();

    cout << endl;
    q.removeTop();
    q.removeTop();
    q.removeTop();
    q.removeTop();
    q.removeTop();
    q.removeTop();   // queue is empty now

    return 0;
}
