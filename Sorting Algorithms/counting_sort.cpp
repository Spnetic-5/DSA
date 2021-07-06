// --------------------------------------------------------------------------- COUNTING SORT --------------------------------------------------------------------------------
// Time Complexity : O(N + maxElement)
// Space Complexity : O(maxElement)
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

void counting_sort(vector<int> &arr){
    int n = arr.size();
    int mac = 0;
    
    
    // find the max element
    for(auto i : arr){
        mac = max(i, mac);
    }

    vector<int> count(mac +1);
    for(auto i : arr){
        count[i]++;
    }


    int i = 0;
    for(int j=0; j<= mac; j++){
        for(int k = 0; k < count[j]; k++){
            arr[i++] = j;
        }
    }


}

int main()
{
    vector<int> arr = { 6, 7, 2, 3, 55, 98, 11, 3};    
    counting_sort(arr);
    for (auto a : arr) cout << a << endl;
}