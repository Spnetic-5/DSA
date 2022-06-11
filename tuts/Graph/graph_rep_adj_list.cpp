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
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // ---------- For weighted Graph
    
    // vector<pair<int, int>> adj[n+1];

    // for(int i = 0; i < n; i++){
    //     adj[i].push_back({0,0});
    // }

    // for(int i = 0; i < m; i++){
    //     int u, v, wt;
    //     cin >> u >>v >> wt;

    //     adj[u].push_back({v, wt});
    //     adj[v].push_back({u, wt});
    // }

    // for(int i = 0; i < n; i++){
    //     cout<<adj[i][1].first<<" ";
    //     cout<<adj[i][1].second<<endl;
    // }   

    return 0;
}