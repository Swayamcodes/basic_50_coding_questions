// ------------------------------------------------------------
// 🚀 Problem 9: Count Frequency of Each Element in an Array
// 💡 Two Approaches: Manual Nested Loop & Using Hash Map
// ------------------------------------------------------------

#include <iostream>
#include <unordered_map>
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
    // ✅ Approach 1: Manual method (without STL)
    // ------------------------------------------------------------
    cout << "\n[Approach 1] Using Manual Nested Loop:\n";
    bool visited[100] = {false}; // track elements already counted

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue; // skip already counted

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = true; // mark as counted
            }
        }
        cout << arr[i] << " -> " << count << " times\n";
    }

    // ------------------------------------------------------------
    // ✅ Approach 2: Using Hash Map (unordered_map)
    // ------------------------------------------------------------
    cout << "\n[Approach 2] Using Hash Map (unordered_map):\n";
    unordered_map<int, int> freq;

    // Count frequency
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print results
    for (auto it : freq) {
        cout << it.first << " -> " << it.second << " times\n";
    }

    return 0;
}

/*
🧪 Sample Input:
6
10 20 10 30 20 10

💡 Expected Output:
[Approach 1] Using Manual Nested Loop:
10 -> 3 times
20 -> 2 times
30 -> 1 time

[Approach 2] Using Hash Map (unordered_map):
30 -> 1 times
20 -> 2 times
10 -> 3 times
*/

// 🧪 To compile and run:
// g++ Q9_CountFrequencyOfElements.cpp -o q9 && ./q9
