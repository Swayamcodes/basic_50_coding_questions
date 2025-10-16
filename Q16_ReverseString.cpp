// ------------------------------------------------------------
// 🚀 Problem 16: Reverse a String
// 💡 Task: Given a string, reverse it and print the result.
// ------------------------------------------------------------
//
// 🧠 Concept:
// To reverse a string, we can use:
// 1️⃣ Two-pointer approach — swap characters from both ends.
// 2️⃣ STL function reverse() — simple and clean.
//
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm> // for reverse()
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    // ------------------------------------------------------------
    // ✅ Approach 1: Manual (Two-pointer method)
    // ------------------------------------------------------------
    string manual = str; // make a copy
    int start = 0;
    int end = manual.length() - 1;

    while (start < end) {
        swap(manual[start], manual[end]);
        start++;
        end--;
    }

    cout << "\n[Manual Method] Reversed String: " << manual << endl;

    // ------------------------------------------------------------
    // ✅ Approach 2: STL reverse() function
    // ------------------------------------------------------------
    string builtin = str;
    reverse(builtin.begin(), builtin.end());
    cout << "[STL Method] Reversed String: " << builtin << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
hello

💡 Expected Output:
[Manual Method] Reversed String: olleh
[STL Method] Reversed String: olleh
------------------------------------------------------------

🧮 Dry Run:
str = "hello"
start=0, end=4
swap(str[0], str[4]) → "oellh"
swap(str[1], str[3]) → "olleh"
✅ Done

------------------------------------------------------------
⏱️ Time Complexity:
O(n) — each character is visited once
🧮 Space Complexity:
O(1) — in-place reversal
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q16_ReverseString.cpp -o q16 && ./q16
