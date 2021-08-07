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
 
int largestSubarray(vector<int>& arr){

    unordered_map<int, int> mpp;
    int count=0;
    int sum=0;
    n = arr.size();
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            count = i+1;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                count = max(count, i - mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
    } 
    return count;

}


int main()
{
    return 0;
}