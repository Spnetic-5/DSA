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
 
vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> mergeIntervals;
    if(intervals.size()==0){
        return mergeIntervals;
    }
    
    sort(intervals.begin(), intervals.end());

    vector<int> tempInterval = intervals[0];

    for(auto it : intervals){
        // cout<<it[0]<<" "<<tempInterval[1]<<endl;
        if(it[0]< tempInterval[1]){
            tempInterval[1] = max(it[1], tempInterval[1]);
        } else{
            mergeIntervals.push_back(tempInterval);
            tempInterval = it; 
        }
    }
    
    mergeIntervals.push_back(tempInterval);
    return mergeIntervals;
}

int main()
{       
    vector<vector<int>> arr{ {1,3}, {2,6}, {8,10}, {15,18} };
    vector<vector<int>> mergeIntervals = merge(arr);
    for (int i = 0; i < mergeIntervals.size(); i++) {
        for (
            auto it = mergeIntervals[i].begin();
            it != mergeIntervals[i].end(); it++)
            cout << *it << " ";
            cout<<endl;
    }
    return 0;
}