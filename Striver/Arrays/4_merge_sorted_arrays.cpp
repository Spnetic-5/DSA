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

void printArray(int arr[], int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



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