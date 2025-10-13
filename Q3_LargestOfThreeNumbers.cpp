// ------------------------------------------------------------
// 🚀 Problem 3: Largest of Three Numbers
// 💡 Task: Read three integers and print the largest one.
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🧠 Function to find the largest among three numbers
    int largest(int a, int b, int c) {
        if (a >= b && a >= c) {
            return a;
        } 
        else if (b >= a && b >= c) {
            return b;
        } 
        else {
            return c;
        }
    }
};

// OR we can do it in one line as:
// return max({a, b, c});

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input: three integers
    int a, b, c;
    cin >> a >> b >> c;

    // Create an object of Solution class
    Solution obj;

    // Output the largest number
    cout << obj.largest(a, b, c);

    return 0;
}
