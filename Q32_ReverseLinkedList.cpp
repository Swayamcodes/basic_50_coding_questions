// ============================================================
// 🚀 Problem 32: Reverse a Linked List (Iterative Approach)
// ============================================================
//
// 🧠 Concept Summary:
// In a linked list, each node points to the next one.
// To reverse the list, we need to make each node point to its previous node.
//
// ------------------------------------------------------------
// Example:
//
// Original:   head → [10|*] → [20|*] → [30|*] → NULL
// Reversed:   head → [30|*] → [20|*] → [10|NULL]
//
// ------------------------------------------------------------
// 🧩 How it Works (Step-by-Step):
//
// We use three pointers:
//   1️⃣ prev  — stores the previous node
//   2️⃣ curr  — the current node we're processing
//   3️⃣ next  — temporarily stores the next node
//
// At each step:
//   next = curr->next
//   curr->next = prev
//   prev = curr
//   curr = next
//
// When curr becomes NULL, prev will be the new head.
//
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

    // Insert node at end (for testing)
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

    // ✅ Reverse the linked list (iteratively)
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;    // Save next node
            curr->next = prev;    // Reverse the link
            prev = curr;          // Move prev ahead
            curr = next;          // Move curr ahead
        }

        head = prev;  // Update head to new front
    }
};

// ============================================================
// 🧮 MAIN FUNCTION — Demonstration
// ------------------------------------------------------------
int main() {
    List ll;

    // Insert some elements
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);

    cout << "Original List:\n";
    ll.printLL();

    // Reverse the list
    ll.reverse();

    cout << "\nReversed List:\n";
    ll.printLL();

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Output:
Original List:
Linked List: 10 -> 20 -> 30 -> 40 -> NULL

Reversed List:
Linked List: 40 -> 30 -> 20 -> 10 -> NULL
------------------------------------------------------------
🧮 Dry Run (step by step):

Initial:
prev = NULL, curr = 10
next = 20
curr->next = NULL (reversed link)
prev = 10, curr = 20

Next:
next = 30
curr->next = 10
prev = 20, curr = 30
...

Finally:
head = prev = 40
✅ Reversal done
------------------------------------------------------------
⏱️ Time Complexity: O(n)
🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q32_ReverseLinkedList.cpp -o q32 && ./q32
