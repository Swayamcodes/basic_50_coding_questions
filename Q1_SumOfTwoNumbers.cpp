// ----------------------------------------------------
// 🚀 Problem 1: Sum of Two Numbers
// 💡 Concept: Basic Input/Output
// 🎯 Task: Read two integers from input and print their sum.
// ----------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🧠 Function to return sum of two numbers
    // TODO: Write your logic here
    int add(int a, int b) {
        return a + b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution obj;

    // Input section
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // Output section
    cout << "Sum: " << obj.add(a, b) << "\n";

    return 0;
}
