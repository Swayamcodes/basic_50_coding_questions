#include <iostream>
using namespace std;
#include <vector>


class Stack {
    vector<int> v;

public:
    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        v.pop_back();
    }

    int top() {
        return v[v.size()-1];
    }

    bool empty() {
        return v.size() == 0;
    }

};

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class StackLL {
    Node* head;

public:
    StackLL() {
        head = NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
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
    // Vector-based Stack
    cout << "Vector Stack: ";
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    // Linked List-based Stack
    cout << "Linked List Stack: ";
    StackLL sll;

    sll.push(10);
    sll.push(20);
    sll.push(30);

    while (!sll.empty()) {
        cout << sll.top() << " ";
        sll.pop();
    }
    cout << endl;

    return 0;
}
