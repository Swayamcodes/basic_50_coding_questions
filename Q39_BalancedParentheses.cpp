// ============================================================
// 🚀 Problem 39: Check Balanced Parentheses using Stack
// ============================================================
//
// 🧠 Concept Summary:
// A string has balanced parentheses if each opening bracket
// has a matching closing bracket in the correct order.
//
// ✅ Types of brackets:
// ()  {}  []
//
// Example:
// Input:  "{[()()]}"
// Output: Balanced
//
// Input:  "{[(])}"
// Output: Not Balanced
// ------------------------------------------------------------

#include <iostream>
#include <stack>
using namespace std;

// ✅ Function to check if parentheses are balanced
bool isBalanced(string s) {
    stack<char> st;

    for (char ch : s) {
        // If opening bracket → push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // If closing bracket → check top
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty())
                return false; // no matching opening bracket

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // Stack should be empty at the end
    return st.empty();
}

// ============================================================
// 🧮 MAIN FUNCTION — Demonstration
// ------------------------------------------------------------
int main() {
    string s;
    cout << "Enter an expression: ";
    cin >> s;

    if (isBalanced(s))
        cout << "✅ Balanced" << endl;
    else
        cout << "❌ Not Balanced" << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input 1:
{[()()]}

💡 Output:
✅ Balanced

🧪 Sample Input 2:
{[(])}

💡 Output:
❌ Not Balanced
------------------------------------------------------------
⏱️ Time Complexity: O(n)
🧮 Space Complexity: O(n)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q39_BalancedParentheses.cpp -o q39 && ./q39
