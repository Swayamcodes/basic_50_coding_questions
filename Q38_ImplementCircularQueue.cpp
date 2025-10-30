// ============================================================
// 🚀 Problem 38: Implement Circular Queue using Array
// ============================================================
//
// 🧠 Concept Summary:
// A Circular Queue allows elements to wrap around the end of the array.
//
// ✅ Advantage:
// Unlike normal queues, space can be reused efficiently.
//
// ✅ Operations:
// 1️⃣ enqueue(x) → Add element at rear
// 2️⃣ dequeue()  → Remove element from front
// 3️⃣ front()    → Access the front element
// 4️⃣ isEmpty()  → Check if queue is empty
// 5️⃣ isFull()   → Check if queue is full
//
// ------------------------------------------------------------
// Example:
//
// Capacity = 5
// enqueue(10), enqueue(20), enqueue(30), dequeue(), enqueue(40), enqueue(50)
// ✅ The next enqueue will wrap around and reuse the freed space.
// ------------------------------------------------------------

#include <iostream>
using namespace std;

// ✅ Circular Queue class
class CircularQueue {
private:
    int *arr;
    int size;
    int front;
    int rear;
    int count; // track number of elements

public:
    // Constructor
    CircularQueue(int capacity) {
        size = capacity;
        arr = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    // ✅ Check if full
    bool isFull() {
        return count == size;
    }

    // ✅ Check if empty
    bool isEmpty() {
        return count == 0;
    }

    // ✅ Add element
    void enqueue(int val) {
        if (isFull()) {
            cout << "❌ Queue Overflow! Cannot enqueue " << val << endl;
            return;
        }

        rear = (rear + 1) % size; // wrap around
        arr[rear] = val;
        count++;
        cout << "✅ Enqueued " << val << endl;
    }

    // ✅ Remove element
    void dequeue() {
        if (isEmpty()) {
            cout << "❌ Queue Underflow! Nothing to dequeue." << endl;
            return;
        }

        cout << "🗑️ Dequeued " << arr[front] << endl;
        front = (front + 1) % size;
        count--;
    }

    // ✅ Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "⚠️ Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // ✅ Display queue contents
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue (front → rear): ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % size;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    // ✅ Destructor
    ~CircularQueue() {
        delete[] arr;
    }
};

// ============================================================
// 🧮 MAIN FUNCTION — Demonstration
// ------------------------------------------------------------
int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // wraps around here
    q.display();

    cout << "🔹 Front element: " << q.getFront() << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Output:
✅ Enqueued 10
✅ Enqueued 20
✅ Enqueued 30
✅ Enqueued 40
Queue (front → rear): 10 20 30 40
🗑️ Dequeued 10
🗑️ Dequeued 20
Queue (front → rear): 30 40
✅ Enqueued 50
✅ Enqueued 60
✅ Enqueued 70
Queue (front → rear): 30 40 50 60 70
🔹 Front element: 30
------------------------------------------------------------
🧮 Dry Run:
size=5
rear = (rear+1) % size → wraps around
count tracks number of elements
------------------------------------------------------------
⏱️ Time Complexity:
enqueue() → O(1)
dequeue() → O(1)
getFront() → O(1)
display() → O(n)
🧮 Space Complexity: O(n)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q38_ImplementCircularQueue.cpp -o q38 && ./q38
