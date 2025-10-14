// ------------------------------------------------------------
// 🚀 Problem 7: Find Maximum and Minimum in an Array
// 💡 Two Approaches: Manual Comparison & Using STL max()/min()
// ------------------------------------------------------------

#include <iostream>
#include <algorithm> // for max(), min()
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ------------------------------------------------------------
    // ✅ Approach 1: Manual Comparison (No STL)
    // ------------------------------------------------------------
    int maxNum = arr[0];
    int minNum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxNum)
            maxNum = arr[i];
        if (arr[i] < minNum)
            minNum = arr[i];
    }

    cout << "\n[Approach 1] Without STL Functions\n";
    cout << "Maximum = " << maxNum << endl;
    cout << "Minimum = " << minNum << endl;


    // ------------------------------------------------------------
    // ✅ Approach 2: Using STL max() and min()
    // ------------------------------------------------------------
    int maxVal = arr[0];
    int minVal = arr[0];

    for (int i = 1; i < n; i++) {
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
    }

    cout << "\n[Approach 2] Using STL max() / min()\n";
    cout << "Maximum = " << maxVal << endl;
    cout << "Minimum = " << minVal << endl;

    return 0;
}

/*
🧪 Sample Input:
5
10 25 8 90 12

💡 Expected Output:
[Approach 1] Without STL Functions
Maximum = 90
Minimum = 8

[Approach 2] Using STL max() / min()
Maximum = 90
Minimum = 8
*/

// 🧪 To compile and run:
// g++ Q7_FindMaxMinInArray.cpp -o q7 && ./q7
