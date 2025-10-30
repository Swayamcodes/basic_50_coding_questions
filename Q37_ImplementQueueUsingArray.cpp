// ============================================================
// 🚀 Problem 37: Implement Queue using Array
// ============================================================
//
// 🧠 Concept Summary:
// A Queue is a **FIFO (First In, First Out)** data structure.
//
// ✅ Common Operations:
// 1️⃣ enqueue(x) → Add element at the REAR
// 2️⃣ dequeue()  → Remove element from the FRONT
// 3️⃣ front()    → Get front element
// 4️⃣ isEmpty()  → Check if queue is empty
// 5️⃣ isFull()   → Check if queue is full
//
// ------------------------------------------------------------
// Example:
// enqueue(10), enqueue(20), enqueue(30)
// Queue: [10, 20, 30]
// dequeue() → removes 10
// Queue becomes: [20, 30]
// ------------------------------------------------------------

#include <iostream>
using namespace std;

// ✅ Queue class implemented using Array
class Queue {
private:
    int arr[100];
    int frontIndex;
    int rearIndex;
    int size;

public:
    // Constructor
    Queue(int capacity = 100) {
        size = capacity;
        frontIndex = 0;
        rearIndex = -1;
    }

    // ✅ Add element to rear
    void enqueue(int val) {
        if (rearIndex == size - 1) {
            cout << "❌ Queue Overflow! Cannot enqueue " << val << endl;
            return;
        }
        rearIndex++;
        arr[rearIndex] = val;
        cout << "✅ Enqueued " << val << endl;
    }

    // ✅ Remove element from front
    void dequeue() {
        if (frontIndex > rearIndex) {
            cout << "❌ Queue Underflow! Nothing to dequeue." << endl;
            return;
        }
        cout << "🗑️ Dequeued " << arr[frontIndex] << endl;
        frontIndex++;
    }

    // ✅ Get front element
    int front() {
        if (frontIndex > rearIndex) {
            cout << "⚠️ Queue is empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // ✅ Check if queue is empty
    bool isEmpty() {
        return frontIndex > rearIndex;
    }

    // ✅ Print queue
    void printQueue() {
        if (frontIndex > rearIndex) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue (front → rear): ";
        for (int i = frontIndex; i <= rearIndex; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ============================================================
// 🧮 MAIN FUNCTION — Demonstration
// ------------------------------------------------------------
int main() {
    Queue q(5); // capacity = 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQueue();

    cout << "🔹 Front element: " << q.front() << endl;

    q.dequeue();
    q.printQueue();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // underflow example

    cout << "🔹 Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Output:
✅ Enqueued 10
✅ Enqueued 20
✅ Enqueued 30
Queue (front → rear): 10 20 30
🔹 Front element: 10
🗑️ Dequeued 10
Queue (front → rear): 20 30
🗑️ Dequeued 20
🗑️ Dequeued 30
❌ Queue Underflow! Nothing to dequeue.
🔹 Is queue empty? Yes
------------------------------------------------------------
🧮 Time Complexity:
- enqueue() → O(1)
- dequeue() → O(1)
- front()   → O(1)
- isEmpty() → O(1)
🧮 Space Complexity: O(n)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q37_ImplementQueueUsingArray.cpp -o q37 && ./q37
