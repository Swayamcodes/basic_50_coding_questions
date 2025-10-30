// ============================================================
// 🚀 Problem 34: Detect Loop in a Linked List
// ============================================================
//
// 🧠 Concept Summary:
// A loop (cycle) in a linked list means that some node’s `next`
// pointer points back to a previous node instead of NULL.
//
// Example:
// 10 -> 20 -> 30 -> 40 ↘
//            ↑_________|
//
// The list never ends when you keep following next pointers.
//
// ------------------------------------------------------------
// 💡 Two Ways to Detect a Loop:
//
// 1️⃣ Hashing Method (Extra Space):
//     - Store each visited node address in a set.
//     - If a node is visited twice → loop exists.
//
// 2️⃣ Floyd’s Cycle Detection (Tortoise & Hare) 🐢🐇 (Optimal):
//     - Use two pointers:
//         slow = moves 1 step
//         fast = moves 2 steps
//     - If they meet → loop exists.
//     - If fast or fast->next becomes NULL → no loop.
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

    // Create a loop manually for testing
    void createLoop(int pos) {
        if (head == NULL) return;
        Node* loopNode = NULL;
        Node* temp = head;
        int count = 1;

        while (temp->next != NULL) {
            if (count == pos)
                loopNode = temp;
            temp = temp->next;
            count++;
        }

        // connect last node to loopNode
        if (loopNode != NULL)
            temp->next = loopNode;
    }

    // ✅ Floyd’s Cycle Detection (Efficient)
    bool detectLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;         // 1 step
            fast = fast->next->next;   // 2 steps

            if (slow == fast) {
                cout << "⚠️ Loop detected at node with value: " << slow->data << endl;
                return true;
            }
        }

        cout << "✅ No loop found." << endl;
        return false;
    }
};

// ============================================================
// 🧮 MAIN FUNCTION — Demonstration
// ------------------------------------------------------------
int main() {
    List ll;

    // Create a sample linked list
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);

    cout << "🔹 Checking before loop creation...\n";
    ll.detectLoop();

    // Create a loop manually (connect last node to position 2)
    ll.createLoop(2);

    cout << "\n🔹 Checking after loop creation...\n";
    ll.detectLoop();

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Output:
🔹 Checking before loop creation...
✅ No loop found.

🔹 Checking after loop creation...
⚠️ Loop detected at node with value: 30
------------------------------------------------------------
🧮 Dry Run (Floyd’s Algorithm):

List: 10 -> 20 -> 30 -> 40 -> 50
                 ↑         |
                 |_________|

Initial: slow=head(10), fast=head(10)
Step 1: slow=20, fast=30
Step 2: slow=30, fast=50
Step 3: slow=40, fast=30
Step 4: slow=50, fast=50 ✅ → loop detected
------------------------------------------------------------
⏱️ Time Complexity: O(n)
🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q34_DetectLoopInLinkedList.cpp -o q34 && ./q34
