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
 
vector<vector<int>> pascals(int numRows){
    vector<vector<int>> r(numRows);
    for(int i=0; i < numRows; i++){
        
        r[i].resize(i+1);
        r[i][0] = r[i][i] = 1;

        for(int j=1; j < i; j++){
            r[i][j] = r[i-1][j-1] + r[i-1][j];
        }
    }
    return r;
}

int main()
{   
    int n = 5;
    vector<vector<int>> pascalsT = pascals(n);
    for (int i = 0; i < pascalsT.size(); i++) {
        for (
            auto it = pascalsT[i].begin();
            it != pascalsT[i].end(); it++)
            cout << *it << " ";
            cout<<endl;
    }
    return 0;
}