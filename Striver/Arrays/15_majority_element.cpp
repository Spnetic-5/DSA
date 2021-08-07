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
 
// Moore's Voting Algorithm Majority=N/2

int majorityElement(vector<<int>>& arr){
    int n = arr.size();
    int count = 0;
    int curr = 0;
    
    for(int i=0; i<n;i++){
        if (count == 0){
            curr = arr[i];
        }
        if{ arr[i] == curr;
            count++;
        }
        else{
            count --;
        }
    }
    return curr;

}


// Using extra space and  majority = N/3
vector majorityElement(vector& nums) {
    vector ans;
    int n=nums.size()/3;
    unordered_map< int, int > freq;
    for(int i=0; i < nums.size(); i++){
        freq[nums[i]]++;
    }
    for(auto i : freq){
        if(i.second>n)
            ans.push_back(i.first);
    }
   return ans;
}


int main()
{
    return 0;
}