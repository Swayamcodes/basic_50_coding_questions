// ------------------------------------------------------------
// 🚀 Problem 26: Check Prime Number
// 💡 Task: Given an integer n, check whether it is a prime number.
// ------------------------------------------------------------
//
// 🧠 Concept:
// A number n > 1 is prime if it is divisible only by 1 and itself.
// Instead of checking all numbers up to n-1,
// we only need to check up to √n for divisibility.
//
// Example:
// Input: 7 → Prime
// Input: 12 → Not Prime
// ------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

// ✅ Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;   // 0 and 1 are not prime
    if (n == 2) return true;    // 2 is prime
    if (n % 2 == 0) return false; // even numbers >2 are not prime

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // ------------------------------------------------------------
    // ✅ 1️⃣ Iterative (simple check)
    // ------------------------------------------------------------
    bool flag = true;
    if (n <= 1) flag = false;
    else {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                flag = false;
                break;
            }
        }
    }

    cout << "\nIterative: " << (flag ? "Prime" : "Not Prime");

    // ------------------------------------------------------------
    // ✅ 2️⃣ Optimized sqrt(n) approach
    // ------------------------------------------------------------
    cout << "\nOptimized: " << (isPrime(n) ? "Prime" : "Not Prime") << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
7

💡 Expected Output:
Iterative: Prime
Optimized: Prime
------------------------------------------------------------
🧮 Dry Run:
n=7 → not divisible by 2,3 → Prime
n=12 → divisible by 2 → Not Prime
------------------------------------------------------------
⏱️ Time Complexity:
- Iterative: O(n)
- Optimized: O(√n)
🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q26_CheckPrimeNumber.cpp -o q26 && ./q26
