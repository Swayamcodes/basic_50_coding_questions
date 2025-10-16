// ============================================================
// 🧠 DSA DAY 1 — BASIC PROGRAMMING & ARRAYS (Q1–Q10)
// ============================================================
// Topics Covered:
// 1️⃣ Basic Input / Output
// 2️⃣ Conditional Statements & Loops
// 3️⃣ Arrays — Traversal, Reversal, Max/Min, Sorting Check
// ============================================================
// Each problem summary includes:
// - Problem statement
// - Core logic (1–3 lines)
// - Time & space complexity
// ============================================================

#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

// ============================================================
// Q1️⃣ SUM OF TWO NUMBERS
// ------------------------------------------------------------
void Q1() {
    int a, b; cin >> a >> b;
    cout << a + b << endl;
    // TC: O(1), SC: O(1)
}

// ============================================================
// Q2️⃣ CHECK EVEN OR ODD
// ------------------------------------------------------------
void Q2() {
    int n; cin >> n;
    if (n % 2 == 0) cout << "Even\n"; else cout << "Odd\n";
    // TC: O(1)
}

// ============================================================
// Q3️⃣ LARGEST OF THREE NUMBERS
// ------------------------------------------------------------
void Q3() {
    int a, b, c; cin >> a >> b >> c;
    cout << max({a, b, c}) << endl;
    // TC: O(1)
}

// ============================================================
// Q4️⃣ CHECK LEAP YEAR
// ------------------------------------------------------------
void Q4() {
    int year; cin >> year;
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        cout << "Leap Year\n";
    else
        cout << "Not a Leap Year\n";
    // TC: O(1)
}

// ============================================================
// Q5️⃣ FACTORIAL OF A NUMBER (ITERATIVE + RECURSIVE)
// ------------------------------------------------------------
long long factRec(int n) { return (n == 0) ? 1 : n * factRec(n - 1); }
void Q5() {
    int n; cin >> n;
    long long fact = 1;
    for (int i = 1; i <= n; i++) fact *= i;
    cout << "Iterative: " << fact << "\nRecursive: " << factRec(n) << "\n";
    // TC: O(n)
}

// ============================================================
// Q6️⃣ REVERSE AN ARRAY
// ------------------------------------------------------------
void Q6() {
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int s = 0, e = n - 1;
    while (s < e) swap(arr[s++], arr[e--]);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // TC: O(n)
}

// ============================================================
// Q7️⃣ FIND MAX AND MIN IN ARRAY
// ------------------------------------------------------------
void Q7() {
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int mx = arr[0], mn = arr[0];
    for (int i = 1; i < n; i++) {
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    cout << "Max = " << mx << ", Min = " << mn << "\n";
    // TC: O(n)
}

// ============================================================
// Q8️⃣ SECOND LARGEST ELEMENT
// ------------------------------------------------------------
void Q8() {
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int largest = INT_MIN, second = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) { second = largest; largest = arr[i]; }
        else if (arr[i] > second && arr[i] != largest) second = arr[i];
    }
    if (second == INT_MIN) cout << "No second largest\n";
    else cout << "Second Largest = " << second << "\n";
    // TC: O(n)
}

// ============================================================
// Q9️⃣ COUNT FREQUENCY OF ELEMENTS
// ------------------------------------------------------------
void Q9() {
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) freq[arr[i]]++;
    for (auto it : freq) cout << it.first << " -> " << it.second << " times\n";
    // TC: O(n), SC: O(n)
}

// ============================================================
// 🔟 CHECK IF ARRAY IS SORTED
// ------------------------------------------------------------
void Q10() {
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    bool sorted = true;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) { sorted = false; break; }
    cout << (sorted ? "Array is Sorted" : "Array is Not Sorted") << endl;
    // TC: O(n)
}

// ============================================================
// 🧩 MAIN MENU (for revision run)
// ------------------------------------------------------------
int main() {
    cout << "🧠 DSA DAY 1 — BASICS & ARRAYS\n";
    cout << "Enter problem number (1–10): ";
    int q; cin >> q;
    cout << "Enter input as required:\n\n";
    switch (q) {
        case 1: Q1(); break;
        case 2: Q2(); break;
        case 3: Q3(); break;
        case 4: Q4(); break;
        case 5: Q5(); break;
        case 6: Q6(); break;
        case 7: Q7(); break;
        case 8: Q8(); break;
        case 9: Q9(); break;
        case 10: Q10(); break;
        default: cout << "Invalid choice!\n";
    }
    return 0;
}

/*
============================================================
🧪 Usage:
> g++ Day1_BasicsAndArrays_Revision.cpp -o day1 && ./day1
Then enter problem number (1–10) and provide input.

------------------------------------------------------------
📘 Quick Reference Table

| Q# | Topic                  | Key Concept           | TC | SC |
|----|------------------------|-----------------------|----|----|
| 1  | Sum of Two Numbers     | Basic I/O             | O(1)|O(1)|
| 2  | Even or Odd            | Modulo Logic          | O(1)|O(1)|
| 3  | Largest of Three       | max()                 | O(1)|O(1)|
| 4  | Leap Year Check        | Year divisibility     | O(1)|O(1)|
| 5  | Factorial              | Loop / Recursion      | O(n)|O(1)|
| 6  | Reverse Array          | Two-pointer swap      | O(n)|O(1)|
| 7  | Max & Min              | Traversal + Compare   | O(n)|O(1)|
| 8  | Second Largest         | Track two values      | O(n)|O(1)|
| 9  | Frequency Count        | Hash Map Counting     | O(n)|O(n)|
| 10 | Check Sorted           | Pair Comparison       | O(n)|O(1)|
------------------------------------------------------------
*/
