// ============================================================
// 🧠 DSA DAY 2 — SEARCHING, SORTING & STRINGS (Q11–Q21)
// ============================================================
// Topics Covered:
// 1️⃣ Searching (Linear, Binary)
// 2️⃣ Sorting (Bubble, Insertion, Selection)
// 3️⃣ String Operations (Reverse, Palindrome, Frequency, etc.)
// ============================================================
// Each problem summary includes:
// - Problem statement
// - Core logic (1–3 lines)
// - Time & space complexity
// ============================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// ============================================================
// Q11️⃣ LINEAR SEARCH
// ------------------------------------------------------------
void Q11() {
    int n, key; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> key;
    int index = -1;
    for (int i = 0; i < n; i++) if (arr[i] == key) { index = i; break; }
    cout << (index != -1 ? "Found at index " + to_string(index) : "Not found") << endl;
    // TC: O(n), SC: O(1)
}

// ============================================================
// Q12️⃣ BINARY SEARCH (Iterative + Recursive)
// ------------------------------------------------------------
int binarySearchRec(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] > key) return binarySearchRec(arr, low, mid - 1, key);
    return binarySearchRec(arr, mid + 1, high, key);
}

void Q12() {
    int n, key; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> key;

    int low = 0, high = n - 1, index = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) { index = mid; break; }
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    cout << "Iterative: " << (index != -1 ? to_string(index) : "Not found") << endl;
    cout << "Recursive: " << (binarySearchRec(arr, 0, n - 1, key) != -1 ?
                               to_string(binarySearchRec(arr, 0, n - 1, key)) : "Not found") << endl;
    // TC: O(log n)
}

// ============================================================
// Q13️⃣ BUBBLE SORT
// ------------------------------------------------------------
void Q13() {
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) { swap(arr[j], arr[j + 1]); swapped = true; }
        if (!swapped) break;
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // TC: O(n²), Best O(n)
}

// ============================================================
// Q14️⃣ INSERTION SORT
// ------------------------------------------------------------
void Q14() {
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // TC: O(n²), Best O(n)
}

// ============================================================
// Q15️⃣ SELECTION SORT
// ------------------------------------------------------------
void Q15() {
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // TC: O(n²)
}

// ============================================================
// Q16️⃣ REVERSE A STRING
// ------------------------------------------------------------
void Q16() {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    cout << s << endl;
    // TC: O(n)
}

// ============================================================
// Q17️⃣ CHECK PALINDROME STRING
// ------------------------------------------------------------
void Q17() {
    string s; cin >> s;
    int l = 0, r = s.size() - 1; bool ok = true;
    while (l < r) if (s[l++] != s[r--]) { ok = false; break; }
    cout << (ok ? "Palindrome" : "Not Palindrome") << endl;
    // TC: O(n)
}

// ============================================================
// Q18️⃣ COUNT VOWELS & CONSONANTS
// ------------------------------------------------------------
void Q18() {
    string s; getline(cin >> ws, s);
    int v = 0, c = 0;
    for (char ch : s) {
        ch = tolower(ch);
        if (isalpha(ch)) (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') ? v++ : c++;
    }
    cout << "Vowels=" << v << ", Consonants=" << c << endl;
    // TC: O(n)
}

// ============================================================
// Q19️⃣ CHARACTER FREQUENCY
// ------------------------------------------------------------
void Q19() {
    string s; getline(cin >> ws, s);
    unordered_map<char, int> freq;
    for (char ch : s) if (ch != ' ') freq[ch]++;
    for (auto &p : freq) cout << p.first << " -> " << p.second << endl;
    // TC: O(n)
}

// ============================================================
// Q20️⃣ REMOVE DUPLICATES FROM STRING
// ------------------------------------------------------------
void Q20() {
    string s; cin >> s;
    unordered_set<char> seen;
    int writeIdx = 0;
    for (char ch : s)
        if (seen.find(ch) == seen.end()) { seen.insert(ch); s[writeIdx++] = ch; }
    s.resize(writeIdx);
    cout << s << endl;
    // TC: O(n)
}

// ============================================================
// Q21️⃣ FIND SUBSTRING OCCURRENCES
// ------------------------------------------------------------
void Q21() {
    string str, sub;
    getline(cin >> ws, str);
    getline(cin, sub);
    int cnt = 0;
    for (int i = 0; i <= (int)str.size() - (int)sub.size(); i++)
        if (str.substr(i, sub.size()) == sub) cnt++;
    cout << cnt << endl;
    // TC: O(n*m)
}

// ============================================================
// 🧩 MAIN MENU
// ------------------------------------------------------------
int main() {
    cout << "🧠 DSA DAY 2 — SEARCHING, SORTING & STRINGS\n";
    cout << "Enter problem number (11–21): ";
    int q; cin >> q;
    cout << "Enter input as required:\n\n";
    switch (q) {
        case 11: Q11(); break;
        case 12: Q12(); break;
        case 13: Q13(); break;
        case 14: Q14(); break;
        case 15: Q15(); break;
        case 16: Q16(); break;
        case 17: Q17(); break;
        case 18: Q18(); break;
        case 19: Q19(); break;
        case 20: Q20(); break;
        case 21: Q21(); break;
        default: cout << "Invalid choice!\n";
    }
    return 0;
}

/*
============================================================
🧪 Usage:
> g++ Day2_SearchingSortingStrings_Revision.cpp -o day2 && ./day2
Then enter problem number (11–21) and provide input.

------------------------------------------------------------
📘 Quick Reference Table

| Q# | Topic                      | Key Concept             | TC      | SC |
|----|-----------------------------|--------------------------|----------|----|
|11|Linear Search|Traversal|O(n)|O(1)|
|12|Binary Search|Divide & Conquer|O(log n)|O(1)|
|13|Bubble Sort|Swapping Adjacent|O(n²)|O(1)|
|14|Insertion Sort|Shifting|O(n²)|O(1)|
|15|Selection Sort|Min Selection|O(n²)|O(1)|
|16|Reverse String|Two-pointer / STL|O(n)|O(1)|
|17|Palindrome Check|Mirror Comparison|O(n)|O(1)|
|18|Vowels & Consonants|Character Checks|O(n)|O(1)|
|19|Char Frequency|Hash Map Counting|O(n)|O(k)|
|20|Remove Duplicates|Set Tracking|O(n)|O(k)|
|21|Substring Occurrence|Sliding Window|O(n*m)|O(1)|
------------------------------------------------------------
*/
