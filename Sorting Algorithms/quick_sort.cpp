// --------------------------------------------------------------------------- MREGE SORT --------------------------------------------------------------------------------
// Time Complexity : O(NlogN)
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
 
int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low, j = high;

    while(i<j){
        do{
            i++;
        } while(arr[i]<= pivot);
        do{
            j--;
        } while(arr[j] > pivot);

        if (i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;

}


void quick_sort_rec(vector<int> &arr, int low, int high){   
    if (low>=high) return;
    int pivot = partition(arr, low, high);
    quick_sort_rec(arr, low, pivot);
    quick_sort_rec(arr, pivot+1, high);
}


void quick_sort(vector<int> &arr){
     arr.push_back(INT_MAX);
     int n = arr.size();
     quick_sort_rec(arr, 0, n-1);
     arr.pop_back();
}



int main() {
    vector<int> arr = { 13, 24, 24, 10, 4, 12, 5, 6 };

    quick_sort(arr);

    for (auto a : arr) cout << a << " ";
}