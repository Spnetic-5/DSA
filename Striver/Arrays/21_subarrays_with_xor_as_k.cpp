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
 
int countSubarrays(vector<int>& arr, int F){
    int count = 0;
    int xorr = 0;
    int n = arr.size();
    unordered_map<int, int> mpp;

    for(int i=0;i<n;i++){
        xorr = xorr ^ arr[i];
        if(xorr == F){
            count++;
        }

        if(mpp.find(xorr) != mpp.end()){
            count += mpp[xorr^F];
        }   
        mpp[xorr] += 1;
    }
    return count;

}

int main()
{
    return 0;
}