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
 
double myPow(double x, int n){
    double ans = 1.0;
    long nn = n;

    if (nn<0) = -1 * nn;
    while(nn>0){
        if(n%2 == 0){
            x = x * x;
            nn /= 2;
        }
        else{
            ans = ans * x;
            n -= 1;s
        }
    
    if(n<0) ans = (double)(1.0) / (double)(ans);
    return ans;

    }

}

int main()
{
    return 0;
}