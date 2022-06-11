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
#include <iostream>
 
using namespace std;
 
int main()
{
    int n, m;
    cin>>n>>m;

    int adj[n+1][m+1];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            adj[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout<<"Graph : "<<endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}