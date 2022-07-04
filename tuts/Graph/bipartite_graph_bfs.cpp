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
 
bool bipartiteBfs(int src, vector<int> adj[], int color[]){
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while(!q.empty()){
        int node = q.front(); 
        q.pop();
        
        for(auto it: adj[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n){
    int color[n];
    memset(color, -1, sizeof color); 

    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            if(!bipartiteBfs(i, adj, color)) return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for(int i = 0; i < m; i++){
        int u, v;
        cout<<"Edge : ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (checkBipartite(adj, n)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

    return 0;
}