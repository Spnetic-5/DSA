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
 
// Using Recursion

int countPaths(int i, int j, int n, int m){


    if((i == n-1) or (j == m -1)){
        return 1;
    }

    if((i >= n) or (j >=m)){
        return 0;
    }

    else{
        return countPaths(i+1, j) + countPaths(i, j+1);
    }

}


// Using DP on recusrsion

int countPaths(int i, int j, vector<vector<int>> &dmap){

    int n = 2;
    int m = 3;

    if((i == n-1) or (j == m -1)){
        return 1;
    }

    if((i >= n) or (j >=m)){
        return 0;
    }

    if(dmap[i][j] != -1){
        return dmap[i][j];
    }
    else{
        return dmap[i][j] = countPaths(i+1, j, dmap) + countPaths(i, j+1, dmap);
    }

}


// Using Permutation

int uniqurePaths(int m, int n){
    int N = n + m -2;
    int r = m - 1;
    double res = 1;

    for(int i =0; i < r; i++){
        res = res * (N - r + i) / i;
    }
    return (int)res;
}



int main()
{
    return 0;
}