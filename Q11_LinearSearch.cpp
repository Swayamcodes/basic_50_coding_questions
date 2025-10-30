// ------------------------------------------------------------
// 🚀 Problem 11: Linear Search in an Array
// 💡 Task: Read n elements and a key. Find if the key exists.
// ------------------------------------------------------------
//
// 🧠 Concept:
// Linear Search scans the array sequentially from start to end.
// Compare each element with the target (key).
// If found, return its index; else, report that it’s not found.
//
// 🧩 Example:
// Input:
// 5
// 10 20 30 40 50
// 30
//
// Output:
// Element found at index 2
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

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    

    bool found = false; // flag to track if key is found
    int index = -1;     // store index if found

    // ------------------------------------------------------------
    // ✅ Linear Search Algorithm
    // ------------------------------------------------------------
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = true;
            index = i;
            break; // stop once element is found
        }
    }

    if (found)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input 1:
5
10 20 30 40 50
30
💡 Output:
Element found at index 2

🧪 Sample Input 2:
4
5 9 2 7
3
💡 Output:
Element not found.

------------------------------------------------------------
🧮 Dry Run:
arr = [10, 20, 30, 40, 50], key = 30
i=0 → 10 != 30
i=1 → 20 != 30
i=2 → 30 == 30 ✅ found
Output: "Element found at index 2"

------------------------------------------------------------
⏱️ Time Complexity:
- Best Case: O(1)   (if element is first)
- Worst Case: O(n)  (if element is last or not present)
- Average Case: O(n/2) ≈ O(n)

🧮 Space Complexity: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ Q11_LinearSearch.cpp -o q11 && ./q11
