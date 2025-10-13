// ------------------------------------------------------------
// 🚀 Problem 4: Check Leap Year
// 💡 Task: Given a year, determine whether it is a leap year or not.
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🧠 Function to check if a given year is a leap year
    bool isLeap(int year) {
        // A year is a leap year if:
        // 1. It is divisible by 400, OR
        // 2. It is divisible by 4 but not by 100
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int year;
    cin >> year;

    Solution obj;

    if (obj.isLeap(year))
        cout << "Leap Year";
    else
        cout << "Not a Leap Year";

    return 0;
}
