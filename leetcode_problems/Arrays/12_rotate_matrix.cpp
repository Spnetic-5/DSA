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
 
void rotateMatrix(vector<vector<int>>& arr){

    int n = arr.size();

    for(int i=0; i < n; i++){
        for(int j=0; j < i; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    for(int i=0; i < n; i++){
        reverse(arr[i].begin(), arr[i].end());
    }

    return;
}

int main()
{
    vector<vector<int>> arr{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotateMatrix(arr);

    for (int i = 0; i < arr.size(); i++) {
        for (
            auto it = arr[i].begin();
            it != arr[i].end(); it++)
            cout << *it << " ";
            cout<<endl;
    }

    return 0;
}