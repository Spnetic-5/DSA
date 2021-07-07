#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();

    // perform N iterations (every iteration makes one element sorted)
    for (int itr = 0; itr < n; itr++) {

        // check for all the conc. elements
        for (int i = 0; i < n - 1; i++) {

            // make sure they are in order
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

void insertionSort(vector<int> &arr) {
    int n = arr.size();

    // place every element from 0 .. N-1 in their proper position
    for (int i = 0; i < n; i++) {

        // go towards left and until smaller element in not found
        for (int j = i - 1; j >= 0; j--) {

            // element to left is greater than swap
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }

            // smaller element found then break
            else {
                break;
            }
        }
    }
}

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    // find smallest element for position i
    for (int i = 0; i < n; i++) {

        // find the smallest element in the unsorted array
        int mn = INT_MAX, loc = -1;
        for (int j = i; j < n; j++) {
            if (arr[j] < mn) {
                mn = arr[j];
                loc = j;
            }
        }

        // swap the smallest element from unsorted array with the current elem
        swap(arr[i], arr[loc]);
    }
}

int main() {
    vector<int> arr = { 6, 7, 2, 3, 55, 98, 11, 3 };

    bubbleSort(arr);

    insertionSort(arr);

    selectionSort(arr);

    for (auto a : arr) cout << a << endl;
}