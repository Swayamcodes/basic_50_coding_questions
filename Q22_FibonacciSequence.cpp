// ------------------------------------------------------------
// 🚀 Problem 22: Fibonacci Sequence (Iterative + Recursive)
// 💡 Task: Print the Fibonacci sequence up to n terms.
// ------------------------------------------------------------
//
// 🧠 Concept:
// F(1) = 0, F(2) = 1
// F(n) = F(n-1) + F(n-2)
//
// Example:
// Input: 7
// Output:
// Iterative: 0 1 1 2 3 5 8
// Recursive: 0 1 1 2 3 5 8
// ------------------------------------------------------------

#include <iostream>
using namespace std;

// ✅ Recursive Fibonacci Function
int fib(int n) {
    if (n <= 1)
        return n; // base case (1-based count adjustment done below)
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer.\n";
        return 0;
    }

    // ------------------------------------------------------------
    // ✅ 1️⃣ Iterative Approach
    // ------------------------------------------------------------
    cout << "\nIterative: ";
    int t1 = 0, t2 = 1;
    if (n >= 1) cout << t1;
    if (n >= 2) cout << " " << t2;

    for (int i = 3; i <= n; ++i) {   // ✅ loop starts at 3 (1-based counting)
        int nextTerm = t1 + t2;
        cout << " " << nextTerm;
        t1 = t2;
        t2 = nextTerm;
    }

    // ------------------------------------------------------------
    // ✅ 2️⃣ Recursive Approach
    // ------------------------------------------------------------
    cout << "\nRecursive: ";
    for (int i = 0; i < n; ++i) {
        cout << fib(i) << " ";
    }
    cout << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
7

💡 Expected Output:
Iterative: 0 1 1 2 3 5 8
Recursive: 0 1 1 2 3 5 8
------------------------------------------------------------
🧮 Dry Run (n = 7):
Iterative loop:
i=3 → nextTerm = 0+1 = 1
i=4 → nextTerm = 1+1 = 2
i=5 → nextTerm = 1+2 = 3
i=6 → nextTerm = 2+3 = 5
i=7 → nextTerm = 3+5 = 8
------------------------------------------------------------
⏱️ Time Complexity:
- Iterative: O(n)
- Recursive: O(2^n)
🧮 Space Complexity:
- Iterative: O(1)
- Recursive: O(n)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q22_FibonacciSequence.cpp -o q22 && ./q22
