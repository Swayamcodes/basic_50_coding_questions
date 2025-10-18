// ------------------------------------------------------------
// 🚀 Problem 29: Check Armstrong Number
// 💡 Task: Given an integer n, check whether it is an Armstrong number.
// ------------------------------------------------------------
//
// 🧠 Concept:
// A number is an Armstrong number if the sum of its digits each raised
// to the power of the number of digits equals the number itself.
//
// Example:
// 153 → (1³ + 5³ + 3³) = 153 ✅
// 9474 → (9⁴ + 4⁴ + 7⁴ + 4⁴) = 9474 ✅
// 123 → (1³ + 2³ + 3³) = 36 ❌
//
// Steps:
// 1️⃣ Count number of digits (say 'd').
// 2️⃣ Extract each digit.
// 3️⃣ Compute digit^d and sum it.
// 4️⃣ Compare sum with original number.
//
// ------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int original = n;
    int digits = 0;
    int temp = n;

    // ✅ Step 1: Count digits
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    // ✅ Step 2: Compute sum of each digit^digits
    int sum = 0;
    temp = n;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    // ✅ Step 3: Compare
    if (sum == original)
        cout << "\n" << original << " is an Armstrong Number ✅" << endl;
    else
        cout << "\n" << original << " is NOT an Armstrong Number ❌" << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input 1:
153
💡 Expected Output:
153 is an Armstrong Number ✅

🧪 Sample Input 2:
123
💡 Expected Output:
123 is NOT an Armstrong Number ❌

------------------------------------------------------------
🧮 Dry Run (n = 153):
digits = 3
sum = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153
✅ Armstrong number

------------------------------------------------------------
⏱️ Time Complexity:
O(d) where d = number of digits
🧮 Space Complexity:
O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q29_ArmstrongNumber.cpp -o q29 && ./q29
