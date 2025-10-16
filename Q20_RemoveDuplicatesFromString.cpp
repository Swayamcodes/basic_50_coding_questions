// ------------------------------------------------------------
// 🚀 Problem 20: Remove All Duplicates from a String
// 💡 Task: Given a string, remove duplicate characters and 
// print the result with only the first occurrence of each character.
// ------------------------------------------------------------
//
// 🧠 Concept:
// Use an unordered_set<char> to track which characters
// have already been seen while traversing the string.
// Append each character to result only if it's not seen before.
//
// Example:
// Input:  programming
// Output: progamin
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    unordered_set<char> seen;
    string result = "";

    for (char ch : str) {
        // if character not seen before → add to result and mark seen
        if (seen.find(ch) == seen.end()) {
            result += ch;
            seen.insert(ch);
        }
    }

    cout << "String after removing duplicates: " << result << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
programming

💡 Expected Output:
progamin
------------------------------------------------------------

🧮 Dry Run:
str = "programming"
→ p (new) → result="p"
→ r (new) → result="pr"
→ o (new) → result="pro"
→ g (new) → result="prog"
→ r (exists) → skip
→ a (new) → result="proga"
→ m (new) → result="progam"
→ m (exists) → skip
→ i (new) → result="progami"
→ n (new) → result="progamin"
→ g (exists) → skip
✅ Final: progamin

------------------------------------------------------------
⏱️ Time Complexity: O(n)
🧮 Space Complexity: O(k) (k = number of unique characters)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q20_RemoveDuplicatesFromString.cpp -o q20 && ./q20
