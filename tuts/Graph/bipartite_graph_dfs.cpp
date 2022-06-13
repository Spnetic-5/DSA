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
 
bool bipartiteDfs(int node, vector<int> adj[], int color[]){

    if(color[node] == -1) color[node] = 0;
    
    for(auto it: adj[node]){
        if(color[node] == -1){
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) return false;
        }
        else if(color[it] == color[node]){
            return false;
        }
    }
    return true;
} 

bool checkBipartite(int n, vector<int> adj[]){
    
    int color[n];
    memset(color, -1, sizeof color);

    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            if(!bipartiteDfs(i, adj, color)) return false;
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
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(checkBipartite(n, adj)) cout << "True";
    else cout << "False";

    return 0;
}