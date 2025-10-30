// ============================================================
// 🚀 Problem 31: Complete Singly Linked List Implementation
// ============================================================
//
// 🧠 Concept Summary:
// A Linked List is a linear data structure where elements (nodes)
// are connected using pointers.
//
// Each Node consists of:
//   ➤ data  → stores the value
//   ➤ next  → pointer to the next node
//
// Linked List Variants:
//   1️⃣ Singly Linked List — connects forward only (this one)
//   2️⃣ Doubly Linked List — connects forward and backward
//   3️⃣ Circular Linked List — last node connects back to first
//
// ------------------------------------------------------------
// Core Operations Implemented Here:
//   ✅ push_front(val)   → Insert at beginning
//   ✅ push_back(val)    → Insert at end
//   ✅ pop_front()       → Delete from beginning
//   ✅ pop_back()        → Delete from end
//   ✅ insert(val, pos)  → Insert at specific position
//   ✅ printLL()         → Print entire list
//   ✅ search(key)       → Search element by value
//
// ------------------------------------------------------------
// Example Execution:
// Input Sequence (Operations):
// push_front(10)
// push_front(20)
// push_front(30)
// insert(15, 2)
// printLL()
// search(15)
//
// Output:
// 30 -> 20 -> 15 -> 10 -> NULL
// 2
//
// ------------------------------------------------------------

#include <iostream>
using namespace std;

// ============================================================
// 🧩 NODE CLASS — Represents each element in the Linked List
// ------------------------------------------------------------
class Node {
public:
    int data;     // stores the actual data
    Node* next;   // pointer to the next node

    // Constructor to initialize node with value
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// ============================================================
// 🧱 LIST CLASS — Handles all linked list operations
// ------------------------------------------------------------
class List {
    Node* head;   // pointer to first node
    Node* tail;   // pointer to last node

public:
    // Constructor to initialize an empty list
    List() {
        head = NULL;
        tail = NULL;
    }

    // ------------------------------------------------------------
    // 🟢 INSERTION OPERATIONS
    // ------------------------------------------------------------

    // ✅ 1️⃣ Insert at Beginning
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {         // if list is empty
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;   // link new node to old head
            head = newNode;         // update head
        }
    }

    // ✅ 2️⃣ Insert at End
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {         // empty list
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;   // link current tail to new node
            tail = newNode;         // update tail
        }
    }

    // ✅ 3️⃣ Insert at a Given Position (0-based index)
    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "❌ Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "❌ Position out of bounds!" << endl;
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        // update tail if inserted at end
        if (newNode->next == NULL)
            tail = newNode;
    }

    // ------------------------------------------------------------
    // 🔴 DELETION OPERATIONS
    // ------------------------------------------------------------

    // ✅ 4️⃣ Delete from Beginning
    void pop_front() {
        if (head == NULL) {
            cout << "❌ List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL; // disconnect node
        delete temp;

        // if list becomes empty, reset tail
        if (head == NULL)
            tail = NULL;
    }

    // ✅ 5️⃣ Delete from End
    void pop_back() {
        if (head == NULL) {
            cout << "❌ List is empty!" << endl;
            return;
        }

        if (head == tail) { // only one node
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        temp->next = NULL;
        tail = temp;
    }

    // ------------------------------------------------------------
    // 🔍 SEARCH & DISPLAY
    // ------------------------------------------------------------

    // ✅ 6️⃣ Search for an Element (returns index)
    int search(int key) {
        Node* temp = head;
        int idx = 0;
        while (temp != NULL) {
            if (temp->data == key)
                return idx;
            temp = temp->next;
            idx++;
        }
        return -1; // not found
    }

    // ✅ 7️⃣ Print the Linked List
    void printLL() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// ============================================================
// 🧮 MAIN FUNCTION — Demonstration of Operations
// ------------------------------------------------------------
int main() {
    List ll;

    // Insertion operations
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);

    // Insertion at specific position
    ll.insert(15, 2);

    // Display list
    ll.printLL();

    // Search example
    int key = 15;
    int pos = ll.search(key);
    if (pos != -1)
        cout << "✅ Element " << key << " found at index " << pos << endl;
    else
        cout << "❌ Element not found!" << endl;

    // Deletion examples (uncomment to test)
    // ll.pop_front();
    // ll.pop_back();
    // ll.printLL();

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Output:
Linked List: 30 -> 20 -> 15 -> 10 -> NULL
✅ Element 15 found at index 2
------------------------------------------------------------
🧮 Dry Run:
push_front(10) → [10|NULL]
push_front(20) → [20|10]
push_front(30) → [30|20]
insert(15, 2)  → [30|20|15|10]
------------------------------------------------------------
⏱️ Time Complexity:
push_front → O(1)
push_back  → O(1)
insert     → O(pos)
pop_front  → O(1)
pop_back   → O(n)
search     → O(n)
printLL    → O(n)
------------------------------------------------------------
🧮 Space Complexity: O(n)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q31_CreateAndManipulateLinkedList.cpp -o q31 && ./q31
