#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main() {
    // ========== QUEUE ==========
    cout << "===== QUEUE (FIFO) =====" << endl;
    queue<int> q;

    // push - add elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Queue size: " << q.size() << endl;
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // pop and display all elements
    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl << endl;


    // ========== DEQUE ==========
    cout << "===== DEQUE (Double-Ended Queue) =====" << endl;
    deque<int> dq;

    // push_back - add at end
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // push_front - add at beginning
    dq.push_front(5);
    dq.push_front(1);

    cout << "Deque size: " << dq.size() << endl;
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    // Display all elements
    cout << "Deque elements: ";
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }
    cout << endl;

    // pop_front - remove from beginning
    dq.pop_front();
    cout << "After pop_front: ";
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }
    cout << endl;

    // pop_back - remove from end
    dq.pop_back();
    cout << "After pop_back: ";
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }
    cout << endl;

    // Check if empty
    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl;

    return 0;
}
// ```

// **Output:**
// ```
// ===== QUEUE (FIFO) =====
// Queue size: 4
// Front element: 10
// Back element: 40
// Queue elements: 10 20 30 40 

// ===== DEQUE (Double-Ended Queue) =====
// Deque size: 5
// Front element: 1
// Back element: 30
// Deque elements: 1 5 10 20 30 
// After pop_front: 5 10 20 30 
// After pop_back: 5 10 20 
// Is deque empty? No