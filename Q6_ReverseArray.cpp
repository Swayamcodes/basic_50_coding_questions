// ------------------------------------------------------------
// 🚀 Problem 6: Reverse an Array
// 💡 Task: Given an array of integers, reverse its elements.
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // 🔁 Reverse logic (two-pointer method)
    int start = 0; int end = n-1;
    while (start<end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }


    cout << "Reversed array:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}

// 🧪 To compile and run:
// g++ -std=c++17 Q6_ReverseArray_Simple.cpp -o q6 && ./q6
