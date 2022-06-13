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

void dfs(int node, vector<int> adj[], int vis[], stack<int> &st){

    if(!vis[node]) {
        vis[node] = 1;
        }
    
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, st);
        }
    }
    
    st.push(node);
}

vector<int> topoSort(int N, vector<int> adj[]){

    int vis[N+1];
    stack<int> st;
    memset(vis, 0, sizeof vis);

    for(int i = 0; i <= N; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
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
    }

    vector<int> ans;
    ans = topoSort(n, adj);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}