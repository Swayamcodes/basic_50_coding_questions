#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isEven(int n) {
       if (n%2 == 0) {
        return true;
       } else {
        return false;
       }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Solution obj;
    if (obj.isEven(n))
        cout << "Even";
    else
        cout << "Odd";

    return 0;
}
