// ============================================================
// 🚀 Problem 36: Implement Stack using Array
// ============================================================
//
// 🧠 Concept Summary:
// Stack is a **LIFO (Last In, First Out)** data structure.
//
// The element inserted last is removed first.
//
// ✅ Common Operations:
// 1️⃣ push(x)   → Insert element at the top
// 2️⃣ pop()     → Remove top element
// 3️⃣ top()     → View top element
// 4️⃣ isEmpty() → Check if stack is empty
//
// ------------------------------------------------------------
// Example:
// push(10), push(20), push(30)
// Stack: [10, 20, 30]
// pop() → removes 30
// top() → returns 20
// ------------------------------------------------------------

#include <iostream>
using namespace std;

// ✅ Stack class implemented using Array
class Stack {
private:
    int arr[100];  // static array
    int topIndex;  // tracks top of stack
    int size;      // capacity of stack

public:
    // Constructor
    Stack(int capacity = 100) {
        size = capacity;
        topIndex = -1;  // empty stack
    }

    // ✅ Push element onto stack
    void push(int val) {
        if (topIndex == size - 1) {
            cout << "❌ Stack Overflow! Cannot push " << val << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = val;
        cout << "✅ Pushed " << val << " onto stack." << endl;
    }

    // ✅ Pop element from stack
    void pop() {
        if (topIndex == -1) {
            cout << "❌ Stack Underflow! Nothing to pop." << endl;
            return;
        }
        cout << "🗑️ Popped " << arr[topIndex] << " from stack." << endl;
        topIndex--;
    }

    // ✅ Return top element
    int top() {
        if (topIndex == -1) {
            cout << "⚠️ Stack is empty!" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // ✅ Check if stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // ✅ Print entire stack
    void printStack() {
        if (topIndex == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = topIndex; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ============================================================
// 🧮 MAIN FUNCTION — Demonstration
// ------------------------------------------------------------
int main() {
    Stack st(5); // capacity 5

    st.push(10);
    st.push(20);
    st.push(30);
    st.printStack();

    cout << "🔹 Top element: " << st.top() << endl;

    st.pop();
    st.printStack();

    cout << "🔹 Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

    st.pop();
    st.pop();
    st.pop(); // extra pop to show underflow

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Output:
✅ Pushed 10 onto stack.
✅ Pushed 20 onto stack.
✅ Pushed 30 onto stack.
Stack (top to bottom): 30 20 10
🔹 Top element: 30
🗑️ Popped 30 from stack.
Stack (top to bottom): 20 10
🔹 Is stack empty? No
🗑️ Popped 20 from stack.
🗑️ Popped 10 from stack.
❌ Stack Underflow! Nothing to pop.
------------------------------------------------------------
⏱️ Time Complexity:
- push()  → O(1)
- pop()   → O(1)
- top()   → O(1)
- isEmpty() → O(1)
🧮 Space Complexity: O(n)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q36_ImplementStackUsingArray.cpp -o q36 && ./q36
