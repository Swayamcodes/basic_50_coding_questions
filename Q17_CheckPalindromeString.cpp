// ------------------------------------------------------------
// 🚀 Problem 17: Check if a String is Palindrome
// 💡 Task: Given a string, check whether it reads the same 
// forward and backward.
// ------------------------------------------------------------
//
// 🧠 Concept:
// Compare first and last characters, moving toward the center.
// If all match → palindrome.
// If any mismatch → not palindrome.
// ------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int n = str.length();
    bool isPalindrome = true; // assume true

    int st = 0, end = n - 1;
    while (st < end) {
        if (str[st] != str[end]) {
            isPalindrome = false;
            break; // no need to check further
        }
        st++;
        end--;
    }

    if (isPalindrome)
        cout << "Result: Palindrome" << endl;
    else
        cout << "Result: Not Palindrome" << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input 1:
madam
💡 Expected Output:
Result: Palindrome

🧪 Sample Input 2:
hello
💡 Expected Output:
Result: Not Palindrome
------------------------------------------------------------

🧮 Dry Run:
str = "madam"
st=0, end=4 → 'm'=='m'
st=1, end=3 → 'a'=='a'
st=2, end=2 ✅ done → palindrome

str = "hello"
st=0, end=4 → 'h'!='o' ❌ → break → Not Palindrome
------------------------------------------------------------
⏱️ Time Complexity: O(n)
🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q17_CheckPalindromeString.cpp -o q17 && ./q17
