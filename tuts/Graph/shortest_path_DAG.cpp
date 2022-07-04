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

void topoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[]){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it.first]){
            topoSort(it.first, vis, st, adj);
        }
    }
    st.push(node);
}

void shortestPath(int N, vector<pair<int, int>> adj[], int src){
    
    int vis[N];
    stack<int> st;
    for(int i = 0; i < N; i++){
        topoSort(i, vis, st, adj);
    }

    int dist[N];

    for(int i = 0; i <= N; i++){
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(dist[node] != INT_MAX){
            for(auto it: adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }

    }

    for(int i = 0; i < N; i++){
        cout<<dist[i]<<" ";
    }
} 

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    for(int i = 0; i < m; i++){
        int u, v, wt;
        cout<<"Edge : ";
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    int src;
    cin >> src;
    shortestPath(n, adj, src);
    return 0;
}