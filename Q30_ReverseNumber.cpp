// ------------------------------------------------------------
// 🚀 Problem 30: Reverse a Number
// 💡 Task: Given an integer n, reverse its digits and print the result.
// ------------------------------------------------------------
//
// 🧠 Concept:
// We extract digits one by one using modulus (% 10)
// and build the reversed number using multiplication by 10.
//
// Example:
// Input: 1234
// Steps: 4 → 43 → 432 → 4321
// Output: 4321
//
// ------------------------------------------------------------

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int reversed = 0;
    int original = n;

    // ✅ Extract digits and build reverse
    while (n != 0) {
        int digit = n % 10;          // get last digit
        reversed = reversed * 10 + digit;  // append it
        n /= 10;                     // remove last digit
    }

    cout << "\nReversed number: " << reversed << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input 1:
1234
💡 Expected Output:
Reversed number: 4321

🧪 Sample Input 2:
9070
💡 Expected Output:
Reversed number: 709

------------------------------------------------------------
🧮 Dry Run (n = 1234):
Initial reversed = 0
→ digit = 4 → reversed = 0*10 + 4 = 4
→ digit = 3 → reversed = 4*10 + 3 = 43
→ digit = 2 → reversed = 43*10 + 2 = 432
→ digit = 1 → reversed = 432*10 + 1 = 4321
✅ Output: 4321

------------------------------------------------------------
⏱️ Time Complexity: O(d)  (d = number of digits)
🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q30_ReverseNumber.cpp -o q30 && ./q30

