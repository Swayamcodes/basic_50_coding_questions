// ------------------------------------------------------------
// 🚀 Problem 25: Power of a Number (xⁿ)
// 💡 Task: Calculate x raised to the power n using both
// iterative and recursive approaches.
// ------------------------------------------------------------
//
// 🧠 Concept:
// Example: x = 2, n = 5
// 2⁵ = 2 × 2 × 2 × 2 × 2 = 32
//
// Recursive relation:
// power(x, n) = x * power(x, n - 1)
// Base case: if n == 0 → return 1
//
// Optimized (divide and conquer):
// power(x, n) = power(x, n/2)² if n even
//             = x * power(x, n/2)² if n odd
// ------------------------------------------------------------

#include <iostream>
using namespace std;

// ✅ Recursive Power Function (Simple)
long long powerRec(long long x, int n) {
    if (n == 0)
        return 1;
    return x * powerRec(x, n - 1);
}

// ✅ Recursive Power Function (Optimized)
long long powerFast(long long x, int n) {
    if (n == 0)
        return 1;
    long long half = powerFast(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

int main() {
    long long x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    // ------------------------------------------------------------
    // ✅ 1️⃣ Iterative Approach
    // ------------------------------------------------------------
    long long result = 1;
    for (int i = 1; i <= n; i++)
        result *= x;

    cout << "\nIterative: " << result;

    // ------------------------------------------------------------
    // ✅ 2️⃣ Recursive (Simple)
    // ------------------------------------------------------------
    cout << "\nRecursive: " << powerRec(x, n);

    // ------------------------------------------------------------
    // ✅ 3️⃣ Recursive (Fast Exponentiation)
    // ------------------------------------------------------------
    cout << "\nOptimized Recursive: " << powerFast(x, n) << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
2 5

💡 Expected Output:
Iterative: 32
Recursive: 32
Optimized Recursive: 32
------------------------------------------------------------
🧮 Dry Run (x=2, n=5):
Iterative → 2×2×2×2×2 = 32
Recursive → powerRec(2,5) = 2×powerRec(2,4)
Fast Power → powerFast(2,5)
   half = powerFast(2,2)
   half² = 16
   odd → 2×16 = 32
------------------------------------------------------------
⏱️ Time Complexity:
- Iterative: O(n)
- Simple Recursion: O(n)
- Fast Recursion: O(log n)
🧮 Space Complexity:
- Iterative: O(1)
- Recursion: O(log n)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q25_PowerOfNumber.cpp -o q25 && ./q25
