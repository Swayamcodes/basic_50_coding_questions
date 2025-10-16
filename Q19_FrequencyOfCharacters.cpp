// ------------------------------------------------------------
// 🚀 Problem 19: Frequency of Each Character in a String
// 💡 Task: Given a string, count how many times each character appears.
// ------------------------------------------------------------
//
// 🧠 Concept:
// Use an unordered_map<char, int> to count occurrences of each character.
// Skip spaces and non-printable symbols (optional).
//
// Example:
// Input:  "hello"
// Output:
// h -> 1
// e -> 1
// l -> 2
// o -> 1
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    unordered_map<char, int> freq;

    // ✅ Count frequency of each character (ignore spaces)
    for (char ch : str) {
        if (ch != ' ') { // skip spaces
            freq[ch]++;
        }
    }

    cout << "\nCharacter Frequencies:\n";
    for (auto it : freq) {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
hello world

💡 Expected Output:
h -> 1
e -> 1
l -> 3
o -> 2
w -> 1
r -> 1
d -> 1
------------------------------------------------------------

🧮 Dry Run:
Input: "hello"
Loop:
'h' → +1
'e' → +1
'l' → +1, +2
'o' → +1
✅ Output:
h -> 1, e -> 1, l -> 2, o -> 1
------------------------------------------------------------
⏱️ Time Complexity: O(n)
🧮 Space Complexity: O(k) (where k = number of unique characters)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q19_FrequencyOfCharacters.cpp -o q19 && ./q19
