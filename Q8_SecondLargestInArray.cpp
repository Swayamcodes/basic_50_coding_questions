// ------------------------------------------------------------
// 🚀 Problem 8: Find the Second Largest Element in an Array
// ------------------------------------------------------------

#include <iostream>
#include <climits> // for INT_MIN
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

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest; // update second before largest
            largest = arr[i];
        } 
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN)
        cout << "No second largest element (all elements are same)" << endl;
    else
        cout << "Second Largest = " << secondLargest << endl;

    return 0;
}

/*
🧪 Sample Input:
6
10 25 8 90 12 45

💡 Expected Output:
Second Largest = 45
*/

// 🧪 To compile and run:
// g++ Q8_SecondLargestInArray.cpp -o q8 && ./q8
