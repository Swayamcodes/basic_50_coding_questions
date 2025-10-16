// ------------------------------------------------------------
// 🚀 Problem 12: Binary Search in a Sorted Array
// 💡 Task: Given n sorted elements and a key, find if the key exists.
// ------------------------------------------------------------
//
// 🧠 Concept:
// Binary Search works only for *sorted* arrays.
// Instead of scanning linearly, it divides the array in half each time.
//
// Steps:
// 1️⃣ Start with st = 0 and end = n - 1
// 2️⃣ Find mid = st + (end - st) / 2
// 3️⃣ If key == arr[mid] → found
// 4️⃣ If key < arr[mid] → search left half
// 5️⃣ Else → search right half
// ------------------------------------------------------------

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int st = 0;
    int end = n - 1;
    int index = -1;  // -1 means not found

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] == key) {
            index = mid;
            break; // element found
        }
        else if (key < arr[mid]) {
            end = mid - 1; // go left
        } 
        else {
            st = mid + 1; // go right
        }
    }

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

/*
------------------------------------------------------------
🧪 Sample Input 1:
6
10 20 30 40 50 60
40
💡 Expected Output:
Element found at index 3

🧪 Sample Input 2:
6
10 20 30 40 50 60
35
💡 Expected Output:
Element not found.
------------------------------------------------------------

🧮 Dry Run:
arr = [10, 20, 30, 40, 50, 60], key = 40
st=0, end=5
mid=2 → arr[2]=30 < key → st=3
mid=(3+5)/2=4 → arr[4]=50 > key → end=3
mid=(3+3)/2=3 → arr[3]=40 == key ✅ found index=3

------------------------------------------------------------
⏱️ Time Complexity:
- Best: O(1)
- Average/Worst: O(log n)
🧮 Space: O(1)
------------------------------------------------------------
*/

// 🧪 To compile and run:
// g++ -std=c++17 Q12_BinarySearch.cpp -o q12 && ./q12
