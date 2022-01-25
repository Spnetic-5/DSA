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
 
int maxProfitF(vector<int>& stocks, int n){
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for(int i = 0; i < n; i++){
        minPrice = min(minPrice, stocks[i]);
        maxProfit = max(maxProfit, stocks[i] - minPrice);
    }

    return maxProfit;
}

int main()
{   
    vector<int> stocks{ 1, 2, 3, 4, 5, 3, 9, 8, 6 };
    int n = stocks.size();
    cout<<maxProfitF(stocks, n);

    return 0;
}