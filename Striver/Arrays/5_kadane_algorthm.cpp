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
 

void kadane(int* arr, int n){
    int max_so_far = arr[0], sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if (sum < 0) {
            sum = 0;    
        }
        else
            max_so_far = max(max_so_far, sum);
    }   
    cout << max_so_far << endl;
}

int main()
{
    int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    kadane(arr, n);
    return 0;
}