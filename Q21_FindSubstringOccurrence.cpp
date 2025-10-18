// ------------------------------------------------------------
// 🚀 Problem 21: Find Substring Occurrence
// 💡 Task: Given a string and a substring, count how many times
// the substring appears in the main string.
// ------------------------------------------------------------
//
// 🧠 Concept:
// There are two main ways to solve this:
// 1️⃣ Manual Sliding Window → check every possible index.
// 2️⃣ STL find() → use built-in search function repeatedly.
//
// ------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, sub;
    cout << "Enter main string: ";
    getline(cin, str);

    cout << "Enter substring: ";
    getline(cin, sub);

    int count = 0;

    // ------------------------------------------------------------
    // ✅ Approach 1: Manual Sliding Window
    // ------------------------------------------------------------
    for (int i = 0; i <= str.length() - sub.length(); i++) {
        if (str.substr(i, sub.length()) == sub) {
            count++;
        }
    }

    cout << "\n[Manual] Occurrences: " << count << endl;

    // ------------------------------------------------------------
    // ✅ Approach 2: Using STL find() method
    // ------------------------------------------------------------
    int count2 = 0;
    size_t pos = str.find(sub); // find first occurrence

    while (pos != string::npos) {
        count2++;
        pos = str.find(sub, pos + 1); // continue searching
    }

    cout << "[STL find()] Occurrences: " << count2 << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
abababa
aba

💡 Expected Output:
[Manual] Occurrences: 3
[STL find()] Occurrences: 3
------------------------------------------------------------

🧮 Dry Run:
str = "abababa", sub = "aba"
i=0 → "aba" ✅
i=1 → "bab" ❌
i=2 → "aba" ✅
i=3 → "bab" ❌
i=4 → "aba" ✅
✅ Total = 3

------------------------------------------------------------
⏱️ Time Complexity:
- Manual Loop: O(n * m)
- STL find(): O(n) average (optimized)
🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q21_FindSubstringOccurrence.cpp -o q21 && ./q21
