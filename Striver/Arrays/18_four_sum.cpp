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

vector<vector<int>> fourSum(vector<int>& arr, int target){
    vector<vector<int>> res;
    
    if(arr.empty()){
        return res;
    }

    int n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i = 0; i<n; i++){
        for(int j = i+1; j < n; j++){
            int target_2 = target - (arr[i] + arr[j]);
            int left = j + 1;
            int right = n -1;
            while(left<right){
                int lr_sum = arr[left] + arr[right];
                if(lr_sum<target_2){
                    left++;
                }
                else if(lr_sum > target_2){
                    right--;
                }
                else{
                    vector<int> quadruplet(4,0);
                    quadruplet[0] = arr[i];
                    quadruplet[1] = arr[j];
                    quadruplet[2] = arr[left];
                    quadruplet[3] = arr[right];
                    res.push_back(quadruplet);
                
                // jumping over duplicates from front & back
                while(left<right && arr[left] == quadruplet[2]) ++left;
                while(left<right && arr[right] == quadruplet[3]) --right;
                }

            }
            // jumping over j duplicates
            while(j+1<n && arr[j+1] == arr[j]) ++j;
        }
        // jumping over i duplicates
        while(i+1<n && arr[i+1] == arr[i]) ++i;
    }
    return res;
}

int main()
{
    return 0;
}