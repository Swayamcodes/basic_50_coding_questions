#include <iostream>
using namespace std;
#include <vector>

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* head;
    Node* tail;

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if (tail==NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
    }

    int front() {
        if (head == NULL) {
            return -1; // or throw an exception
        }
        return head->data;
    }
    bool empty() {
        return head == NULL;
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // 10
    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // 20

    q.pop();
    q.pop();
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}