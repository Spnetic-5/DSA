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
 
vector<int> nextP(vector<int>& arr, int n){
    int index1, index2;

    for(int i = n - 2; i >= 0; i--){
        
        if(arr[i]<arr[i+1]){
            index1 = i ;
            break;
        }
    }
    
    if(index1 < 0){
        reverse(arr.begin(), arr.end());
    }
    else{

        for(int j = n - 1; j >= index1; j--){
        
            if(arr[j] > arr[index1]){
                index2 = j;
                break;
            }
        }

        swap(arr[index1], arr[index2]);
        reverse(arr.begin() + 1 + index1, arr.end());
        
    }

    return arr;
   
}

int main()
{   
    vector<int> arr{ 1, 3, 5, 4, 2};
    int n = arr.size();
    nextP(arr, n);

    for (auto it = arr.begin();it != arr.end(); it++){
            cout << *it << " ";
            cout<<endl;
    }

    return 0;
}