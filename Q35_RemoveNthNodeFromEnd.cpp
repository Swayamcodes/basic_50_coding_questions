// ============================================================
// 🚀 Problem 35: Remove Nth Node from End of Linked List
// ============================================================
//
// 🧠 Concept Summary:
// Given a linked list, remove the Nth node from the *end* of the list.
//
// Example:
// Input:  head = [10 -> 20 -> 30 -> 40 -> 50], n = 2
// Output: [10 -> 20 -> 30 -> 50]
//
// ------------------------------------------------------------
// 💡 Two Approaches:
//
// 1️⃣ **Length Counting (2 Passes)**
//     - Find total length of list (len)
//     - Remove (len - n + 1)th node from the start
//
// 2️⃣ **Two-Pointer Method (1 Pass, Optimal)** ✅
//     - Move 'fast' n steps ahead
//     - Then move both 'slow' and 'fast' together
//     - When fast reaches end, slow points to node before the one to delete
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

    List() { head = NULL; }

    // Insert at end
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

    // Print the list
    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // ✅ Method 1: Two-Pointer Technique (Single Pass)
    void removeNthFromEnd(int n) {
        Node* dummy = new Node(0); // dummy node to handle head deletion
        dummy->next = head;
        Node* slow = dummy;
        Node* fast = dummy;

        // Step 1️⃣: Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            if (fast->next == NULL) {
                cout << "❌ n is greater than length of list!" << endl;
                return;
            }
            fast = fast->next;
        }

        // Step 2️⃣: Move both until fast reaches last node
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3️⃣: Delete the node
        Node* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;

        head = dummy->next; // update head
        delete dummy;
    }
};

// ============================================================
// 🧮 MAIN FUNCTION — Demonstration
// ------------------------------------------------------------
int main() {
    List ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);

    cout << "Original Linked List:\n";
    ll.printLL();

    int n;
    cout << "\nEnter position from end to remove: ";
    cin >> n;

    ll.removeNthFromEnd(n);

    cout << "\nUpdated Linked List:\n";
    ll.printLL();

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
n = 2
Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

💡 Expected Output:
10 -> 20 -> 30 -> 50 -> NULL

------------------------------------------------------------
🧮 Dry Run:

fast = dummy
Move fast 2 steps ahead → points to 20
Then move slow & fast together:
 slow=10, fast=30
 slow=20, fast=40
 slow=30, fast=50
✅ slow points before 40 → delete 40
------------------------------------------------------------
⏱️ Time Complexity: O(n)
🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q35_RemoveNthNodeFromEnd.cpp -o q35 && ./q35
