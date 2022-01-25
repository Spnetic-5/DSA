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
 
bool searchMatrix(vector<vector<int>>& matrix, int target){

    if(!matriz.size()) return false;

    n = matrix.size();
    m = matrix[0].size();
    int low = 0;
    int high = (m*n) -1;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(matrix[mid/m][mid%m]== target){
            return true;
        }
        if (matrix[mid/m][mid%m] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;

}

int main()
{
    return 0;
}