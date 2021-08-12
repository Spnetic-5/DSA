#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Brute force approach(extra space) 
int trappingWater(int arr[], int n){
    // Code here
    
int left[n];
int right[n];
int water = 0;
    
left[0] = arr[0];
    
// left max
for (int i = 1; i < n; i++)
    left[i] = max(left[i - 1], arr[i]);
    
right[n - 1] = arr[n - 1];
    
// right max
for (int i = n - 2; i >= 0; i--)
    right[i] = max(right[i + 1], arr[i]);
    
// Trapped water
for (int i = 0; i < n; i++)
    water += min(left[i], right[i]) - arr[i];
    
return water;
};
    

// Space optimisec (two pointer) approach
int trap(int arr[], int n) {
    
 // initialize output
int result = 0;
 
// maximum element on left and right
int left_max = 0, right_max = 0;

// indices to traverse the array
int lo = 0, hi = n - 1;
 
while (lo <= hi) {
    if (arr[lo] < arr[hi]) {
        if (arr[lo] > left_max)
            // update max in left
            left_max = arr[lo];
        else
            // water on curr element = max - curr
            result += left_max - arr[lo];
        lo++;
    }
    else {
        if (arr[hi] > right_max)
            // update right maximum
            right_max = arr[hi];
        else
            result += right_max - arr[hi];
        hi--;
    }
}
 
return result;
    
}


int main() {
    int arr[5] = {6, 7, 8, 3, 8};
    int n = 5;
    cout<<trap(arr,n);
}

