// ------------------------------------------------------------
// 🚀 Problem 27: Print All Prime Numbers in a Range
// 💡 Task: Given two integers L and R, print all prime numbers
// between L and R (inclusive).
// ------------------------------------------------------------
//
// 🧠 Concept:
// A number n > 1 is prime if it has no divisors other than 1 and itself.
// Instead of checking divisibility till n-1, we only need to check till √n.
//
// Example:
// Input: 10 30
// Output: 11 13 17 19 23 29
// ------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

// ✅ Optimized helper function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;      // 0, 1, negatives are not prime
    if (n == 2) return true;       // 2 is prime
    if (n % 2 == 0) return false;  // eliminate even numbers

    // check odd divisors only up to √n
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int L, R;
    cout << "Enter lower and upper range: ";
    cin >> L >> R;

    cout << "\nPrime numbers between " << L << " and " << R << " are:\n";

    // ✅ Loop through the range and print primes
    for (int i = L; i <= R; i++) {
        if (isPrime(i))
            cout << i << " ";
    }

    cout << endl;
    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
10 30

💡 Expected Output:
11 13 17 19 23 29

------------------------------------------------------------
🧮 Dry Run (L=10, R=20):
Check 10 ❌
Check 11 ✅
Check 12 ❌
Check 13 ✅
Check 14 ❌
Check 15 ❌
Check 16 ❌
Check 17 ✅
Check 18 ❌
Check 19 ✅
Check 20 ❌
Output: 11 13 17 19
------------------------------------------------------------
⏱️ Time Complexity:
O((R - L + 1) * √R)
🧮 Space Complexity:
O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q27_PrintPrimesInRange.cpp -o q27 && ./q27
