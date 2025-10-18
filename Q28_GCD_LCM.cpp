// ------------------------------------------------------------
// 🚀 Problem 28: GCD and LCM of Two Numbers
// 💡 Task: Given two integers, find their GCD (HCF) and LCM.
// ------------------------------------------------------------
//
// 🧠 Concept:
//
// ➤ GCD (Greatest Common Divisor):
//    The largest number that divides both a and b.
//    Euclidean Algorithm:
//       gcd(a, b) = gcd(b, a % b)
//       Base case → gcd(a, 0) = a
//
// ➤ LCM (Least Common Multiple):
//    The smallest number divisible by both a and b.
//    Formula:
//       LCM(a, b) = (a * b) / GCD(a, b)
//
// ------------------------------------------------------------
// Example:
// Input: 12 18
// GCD = 6
// LCM = 36
// ------------------------------------------------------------

#include <iostream>
using namespace std;

// ✅ Recursive function to find GCD (Euclidean algorithm)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // ✅ Calculate GCD
    int gcdValue = gcd(a, b);

    // ✅ Calculate LCM using relationship
    int lcmValue = (a * b) / gcdValue;

    cout << "\nGCD (HCF) = " << gcdValue;
    cout << "\nLCM = " << lcmValue << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
12 18

💡 Expected Output:
GCD (HCF) = 6
LCM = 36

------------------------------------------------------------
🧮 Dry Run:
a = 12, b = 18
gcd(12, 18)
→ gcd(18, 12)
→ gcd(12, 6)
→ gcd(6, 0)
✅ GCD = 6
LCM = (12 * 18) / 6 = 36
------------------------------------------------------------
⏱️ Time Complexity:
O(log(min(a, b))) — very efficient
🧮 Space Complexity:
O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q28_GCD_LCM.cpp -o q28 && ./q28
