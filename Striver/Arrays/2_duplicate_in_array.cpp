// Duplicate in an array of N+1 integers
// Time Complexity: O(n) Space Complexity: O(1)

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

int findDuplicate(int* arr, int n) {
    int slow = arr[0];
    int fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    // cout<<"Index "<<slow<<" "<<fast<<endl;

    fast = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 3, 9, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<findDuplicate(arr, n);
    return 0;
}