// Merge Two sorted Arrays 
// Time Complexity: O(n+m) + O(nlogn)
// Space Complexity: O(N)
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 

void mergeArrays(int* arr1, int n, int* arr2, int m){

    int arr3[n+m];

    for (int i = 0; i < n; i++){
        arr3[i] = arr1[i];
    }
    for (int i = 0; i < m; i++){
        arr3[i+n] = arr2[i];
    }

    sort(arr3, arr3+n+m);

    for (int i = 0; i < n; i++){
        arr1[i] = arr3[i];
    }
    for (int i = 0; i < m; i++){
        arr2[i] = arr3[i+n];
    }
}

// Insertion Method(Without extra space)
// Time Complexity:O(N x M)
// Space Complexity: O(1)



void merge1(int arr1[], int arr2[], int m, int n)
{
    
    for (int i = 0; i < m; i++)
    {
        
        if (arr1[i] > arr2[0])
        {
            swap(arr1[i], arr2[0]);
            int first = arr2[0];
 
            int k;
            for (k = 1; k < n && arr2[k] < first; k++) {
                arr2[k - 1] = arr2[k];
            }
 
            arr2[k - 1] = first;
        }
    }
}

// Gap Method 
// Time Complexity: O(logn) x O(N)
// Space Complexity: O(1)

// Function to find next gap.
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
 
void merge2(int* arr1, int* arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap);
         gap > 0; gap = nextGap(gap))
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
 
        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0;
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
 
        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}
 

void printArray(int arr[], int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// Driver code 
int main()
{
    int arr1[10] = {2,3,4,6,7,8,9,10,15,19};
    int arr2[10] = {1,5,11,12,13,14,16,17,18,20};
    int n = 10;
    int m = 10;
    mergeArrays(arr1, n, arr2, m);
    printArray(arr1, n);
    printArray(arr2, m);
    return 0;
}