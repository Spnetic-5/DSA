#include <bits/stdc++.h>
#include <iostream>
using namespace std;


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
    

int main() {
    int arr[5] = {6, 7, 8, 3, 8};
    int n = 5;
    cout<<trappingWater(arr,n);
}


