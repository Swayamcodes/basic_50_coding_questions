// ============================================================
// 🚀 Problem 33: Find the Middle Node of a Linked List
// ============================================================
//
// 🧠 Concept Summary:
// To find the middle node of a linked list efficiently, we use two pointers:
//   🐢 slow  → moves one step at a time
//   🐇 fast  → moves two steps at a time
//
// When the fast pointer reaches the end,
// the slow pointer will be at the middle.
//
// ------------------------------------------------------------
// Example:
// Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
//
// Iterations:
// Step 1: slow = 10, fast = 10
// Step 2: slow = 20, fast = 30
// Step 3: slow = 30, fast = 50
// ✅ slow now points to middle node (30)
// ------------------------------------------------------------

#include <iostream>
using namespace std;

// ✅ Node class
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// ✅ Linked List class
class List {
public:
    Node* head;

    List() {
        head = NULL;
    }

    // Insert node at the end
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // Print linked list
    void printLL() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // ✅ Method 1: Using Slow–Fast Pointers (Efficient)
    void findMiddle_SlowFast() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;         // move 1 step
            fast = fast->next->next;   // move 2 steps
        }

        cout << "Middle (Slow–Fast): " << slow->data << endl;
    }

    // ✅ Method 2: Using Node Counting (Simple)
    void findMiddle_Counting() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        int count = 0;
        Node* temp = head;

        // Count nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int mid = count / 2;
        temp = head;
        for (int i = 0; i < mid; i++)
            temp = temp->next;

        cout << "Middle (Counting): " << temp->data << endl;
    }
};

// ============================================================
// 🧮 MAIN FUNCTION — Demonstration
// ------------------------------------------------------------
int main() {
    List ll;

    // Insert sample nodes
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);

    cout << "Linked List:\n";
    ll.printLL();

    // Find middle using both methods
    cout << endl;
    ll.findMiddle_SlowFast();
    ll.findMiddle_Counting();

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Output:
Linked List:
10 -> 20 -> 30 -> 40 -> 50 -> NULL

Middle (Slow–Fast): 30
Middle (Counting): 30
------------------------------------------------------------
🧮 Dry Run (slow–fast):
Start: slow=10, fast=10
Loop 1: slow=20, fast=30
Loop 2: slow=30, fast=50 (fast reached end)
✅ slow = 30 → middle
------------------------------------------------------------
⏱️ Time Complexity:
- Slow–Fast Method: O(n)
- Counting Method:  O(2n) → count + traverse
🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q33_FindMiddleOfLinkedList.cpp -o q33 && ./q33
