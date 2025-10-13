// ------------------------------------------------------------
// 🚀 Problem 5: Factorial of a Number
// 💡 Task: Given an integer n, calculate its factorial.
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🧠 Iterative approach using loop
    long long factorialIterative(int n) {
        if (n == 0) return 1; // factorial(0) = 1

        long long fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }

    // 🔁 Recursive approach
    long long factorialRecursive(int n) {
        if (n == 0) return 1; // base case
        return n * factorialRecursive(n - 1); // recursive call
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Solution obj;

    // ✅ Using iterative
    cout << "Iterative: " << obj.factorialIterative(n) << "\n";

    // ✅ Using recursion
    cout << "Recursive: " << obj.factorialRecursive(n) << "\n";

    return 0;
}

// 🧪 To compile and run:
// g++ -std=c++17 Q5_FactorialOfNumber.cpp -o q5 && ./q5
