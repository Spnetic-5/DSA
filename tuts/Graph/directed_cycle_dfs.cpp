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

bool dfsCycle(int node, vector<int> adj[], int vis[], int dfsvis[]){

    if(!vis[node]) {
        vis[node] = 1;
        dfsvis[node] = 1;
        }
    
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfsCycle(it, adj, vis, dfsvis)) return true;
        }
        else if(dfsvis[it] == 1){
            return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}

bool detectCycle(int N, vector<int> adj[]){
    int vis[N+1];
    int dfsvis[N+1];
    memset(vis, 0, sizeof vis);
    memset(dfsvis, 0, sizeof dfsvis);

    for(int i = 0; i <= N; i++){
        if(!vis[i]){
            if(dfsCycle(i, adj, vis, dfsvis)) return true;
        }
    }
    return false;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for(int i = 0; i < m; i++){
        int u, v;
        cout<<"Here : ";
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (detectCycle(n, adj)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

    return 0;
}