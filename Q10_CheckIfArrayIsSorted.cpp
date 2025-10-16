// ------------------------------------------------------------
// 🚀 Problem 10: Check if an Array is Sorted
// ------------------------------------------------------------
// 🧠 Objective:
// Given an array of integers, determine whether it is sorted in
// non-decreasing (ascending) order.
//
// Example:
// Input:  [1, 2, 3, 4, 5]
// Output: "Array is Sorted"
//
// Input:  [5, 3, 8, 1, 2]
// Output: "Array is Not Sorted"
//
// ------------------------------------------------------------

#include <iostream>
#include <algorithm> // for is_sorted (STL version)
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
    // ✅ Approach 1: Manual Check using Loop
    // ------------------------------------------------------------
    bool sorted = true; // assume array is sorted

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            sorted = false;
            break; // no need to check further
        }
    }

    if (sorted)
        cout << "\n[Approach 1] Array is Sorted" << endl;
    else
        cout << "\n[Approach 1] Array is Not Sorted" << endl;

    // ------------------------------------------------------------
    // ✅ Approach 2: Using STL function is_sorted()
    // ------------------------------------------------------------
    // The STL algorithm checks if each element is <= the next one.
    if (is_sorted(arr, arr + n))
        cout << "[Approach 2] Array is Sorted (via STL)" << endl;
    else
        cout << "[Approach 2] Array is Not Sorted (via STL)" << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input 1:
5
1 2 3 4 5

💡 Expected Output:
[Approach 1] Array is Sorted
[Approach 2] Array is Sorted (via STL)

------------------------------------------------------------
🧪 Sample Input 2:
5
5 3 8 1 2

💡 Expected Output:
[Approach 1] Array is Not Sorted
[Approach 2] Array is Not Sorted (via STL)

------------------------------------------------------------
🧩 Explanation:
- We loop through the array from index 0 to n-2.
- If we find any element greater than its next element (arr[i] > arr[i+1]),
  that means the array is NOT sorted.
- If no such pair exists, then the array is sorted.
- STL’s `is_sorted()` performs the same check internally.

------------------------------------------------------------
⏱️ Time Complexity: O(n)
🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ Q10_CheckIfArrayIsSorted.cpp -o q10 && ./q10
