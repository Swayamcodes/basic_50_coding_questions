// ------------------------------------------------------------
// 🚀 Problem 23: Sum of Digits of a Number
// 💡 Task: Given an integer n, find the sum of its digits
// using both iterative and recursive approaches.
// ------------------------------------------------------------
//
// 🧠 Concept:
// Example: n = 1234 → 1 + 2 + 3 + 4 = 10
//
// Recursive relation:
// sumDigits(n) = (n % 10) + sumDigits(n / 10)
// Base case: if n == 0 → return 0
// ------------------------------------------------------------

#include <iostream>
using namespace std;

// ✅ Recursive function
int sumDigits(int n) {
    if (n == 0)
        return 0; // base case
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // ------------------------------------------------------------
    // ✅ 1️⃣ Iterative Approach
    // ------------------------------------------------------------
    int temp = n, sum = 0;
    while (temp != 0) {
        sum += temp % 10;  // extract last digit
        temp /= 10;        // remove last digit
    }
    cout << "\nIterative: " << sum;

    // ------------------------------------------------------------
    // ✅ 2️⃣ Recursive Approach
    // ------------------------------------------------------------
    cout << "\nRecursive: " << sumDigits(n) << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
1234
💡 Expected Output:
Iterative: 10
Recursive: 10
------------------------------------------------------------
⏱️ TC: O(d), SC: O(1)/O(d)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q23_SumOfDigits.cpp -o q23 && ./q23
