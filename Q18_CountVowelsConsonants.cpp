// ------------------------------------------------------------
// 🚀 Problem 18: Count Vowels and Consonants
// 💡 Task: Given a string, count the number of vowels and consonants.
// ------------------------------------------------------------
//
// 🧠 Concept:
// - Vowels: a, e, i, o, u (case-insensitive)
// - Consonants: all other alphabetic characters
// - Ignore digits, spaces, and symbols.
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <cctype> // for tolower() and isalpha()
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str); // reads entire line including spaces

    int vowels = 0, consonants = 0;

    for (char ch : str) {
        ch = tolower(ch); // convert to lowercase for easy comparison

        if (isalpha(ch)) { // check only alphabets
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    cout << "\nVowels = " << vowels << ", Consonants = " << consonants << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
Hello World

💡 Expected Output:
Vowels = 3, Consonants = 7
------------------------------------------------------------

🧮 Dry Run:
Input: "Hello World"
→ h (consonant)
→ e (vowel)
→ l (consonant)
→ l (consonant)
→ o (vowel)
→ space (ignored)
→ w (consonant)
→ o (vowel)
→ r (consonant)
→ l (consonant)
→ d (consonant)
✅ vowels=3, consonants=7

------------------------------------------------------------
⏱️ Time Complexity: O(n)
🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q18_CountVowelsConsonants.cpp -o q18 && ./q18
