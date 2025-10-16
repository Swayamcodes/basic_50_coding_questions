// ------------------------------------------------------------
// 🚀 Problem 13: Bubble Sort
// 💡 Task: Given n elements, sort them in ascending order 
// using the Bubble Sort algorithm.
// ------------------------------------------------------------
//
// 🧠 Concept:
// Bubble Sort repeatedly compares adjacent elements and swaps them
// if they are in the wrong order.
// After every pass, the largest unsorted element moves ("bubbles") 
// to its correct position at the end.
//
// 🧩 Example:
// Input:  [5, 1, 4, 2, 8]
// Pass 1: [1, 4, 2, 5, 8]
// Pass 2: [1, 2, 4, 5, 8] ✅ Sorted
//
// ------------------------------------------------------------

#include <iostream>
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
    // ✅ Standard Bubble Sort
    // ------------------------------------------------------------
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "\n[Normal] Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // ------------------------------------------------------------
    // ✅ Optimized Bubble Sort (Early Stopping)
    // ------------------------------------------------------------
    int arr2[100];
    for (int i = 0; i < n; i++) arr2[i] = arr[i]; // copy for demo

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr2[j] > arr2[j + 1]) {
                swap(arr2[j], arr2[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // if no swaps in a pass, array is sorted
    }

    cout << "[Optimized] Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input:
5
5 1 4 2 8

💡 Expected Output:
[Normal] Sorted Array: 1 2 4 5 8
[Optimized] Sorted Array: 1 2 4 5 8
------------------------------------------------------------

🧮 Dry Run:
arr = [5,1,4,2,8]
Pass 1: compare (5,1),(5,4),(5,2),(5,8)
→ [1,4,2,5,8]
Pass 2: [1,2,4,5,8]
No swaps after that → done.

------------------------------------------------------------
⏱️ Time Complexity:
- Worst / Average: O(n²)
- Best (already sorted): O(n)
🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q13_BubbleSort.cpp -o q13 && ./q13
