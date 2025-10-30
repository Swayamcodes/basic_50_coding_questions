// ============================================================
// 🚀 Problem 40: Implement Deque using Array
// ============================================================
//
// 🧠 Concept Summary:
// A Deque (Double Ended Queue) allows insertion and deletion
// from both ends — FRONT and REAR.
//
// ✅ Operations:
// 1️⃣ insertFront(x)
// 2️⃣ insertRear(x)
// 3️⃣ deleteFront()
// 4️⃣ deleteRear()
// 5️⃣ getFront()
// 6️⃣ getRear()
// 7️⃣ isEmpty()
// 8️⃣ isFull()
//
// ------------------------------------------------------------
// Example:
// insertRear(10), insertRear(20), insertFront(5)
// Deque: [5, 10, 20]
// deleteRear()
// Deque: [5, 10]
// ------------------------------------------------------------

#include <iostream>
using namespace std;

// ✅ Deque class using Circular Array
class Deque {
private:
    int *arr;
    int front, rear, size, count;

public:
    Deque(int capacity) {
        size = capacity;
        arr = new int[size];
        front = 0;
        rear = size - 1;
        count = 0;
    }

    bool isFull() { return count == size; }
    bool isEmpty() { return count == 0; }

    // ✅ Insert at front
    void insertFront(int val) {
        if (isFull()) {
            cout << "❌ Deque Overflow!" << endl;
            return;
        }
        front = (front - 1 + size) % size;
        arr[front] = val;
        count++;
        cout << "✅ Inserted " << val << " at front." << endl;
    }

    // ✅ Insert at rear
    void insertRear(int val) {
        if (isFull()) {
            cout << "❌ Deque Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = val;
        count++;
        cout << "✅ Inserted " << val << " at rear." << endl;
    }

    // ✅ Delete from front
    void deleteFront() {
        if (isEmpty()) {
            cout << "❌ Deque Underflow!" << endl;
            return;
        }
        cout << "🗑️ Deleted " << arr[front] << " from front." << endl;
        front = (front + 1) % size;
        count--;
    }

    // ✅ Delete from rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "❌ Deque Underflow!" << endl;
            return;
        }
        cout << "🗑️ Deleted " << arr[rear] << " from rear." << endl;
        rear = (rear - 1 + size) % size;
        count--;
    }

    // ✅ Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "⚠️ Deque is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // ✅ Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "⚠️ Deque is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // ✅ Display
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deque (front → rear): ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % size;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    ~Deque() { delete[] arr; }
};

// ============================================================
// 🧮 MAIN FUNCTION — Demonstration
// ------------------------------------------------------------
int main() {
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.display();

    dq.deleteRear();
    dq.display();

    dq.insertFront(2);
    dq.insertRear(30);
    dq.display();

    cout << "🔹 Front element: " << dq.getFront() << endl;
    cout << "🔹 Rear element: " << dq.getRear() << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Output:
✅ Inserted 10 at rear.
✅ Inserted 20 at rear.
✅ Inserted 5 at front.
Deque (front → rear): 5 10 20
🗑️ Deleted 20 from rear.
Deque (front → rear): 5 10
✅ Inserted 2 at front.
✅ Inserted 30 at rear.
Deque (front → rear): 2 5 10 30
🔹 Front element: 2
🔹 Rear element: 30
------------------------------------------------------------
⏱️ Time Complexity:
All operations: O(1)
🧮 Space Complexity: O(n)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q40_ImplementDeque.cpp -o q40 && ./q40
