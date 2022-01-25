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
 
int longestConsecutive(vector<int>& arr){
    
    set<int> hashSet;
    for (int i : arr){
        hashSet.insert(i); 
    }

    int longestStreak;
    for(int i : arr){
        if(!hashSet.count(i-1)){
            int currentStreak = 1;
            int currentNum = i;

            while(hashSet.count(currentNum+1)){
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
        
    }
    return longestStreak;
}


int main()
{
    return 0;
}