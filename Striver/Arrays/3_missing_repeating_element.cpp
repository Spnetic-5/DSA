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

void findRandM(int* arr,int n){
    int sum = 0;
    int r;
    int m;
    int ss = 0;
    int og_sum = n*(n+1)/2;
    int og_ss = n*(n+1)*(2*n+1)/6;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        ss += pow(arr[i],2);
    }   

    int sub_sumsquare = og_ss - ss;
    int sub_sum = og_sum - sum;
    m = (((sub_sumsquare) / (sub_sum)) + (sub_sum)) / 2;
    r = m - sub_sum;

    cout<<"Missing : "<<m<<" "<<"Repeating : "<<r<<endl;
    return;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 3, 9, 8, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findRandM(arr, n);
    return 0;
}