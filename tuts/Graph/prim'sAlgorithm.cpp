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
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n+1];

    for(int i = 0; i < m; i++){
        int u, v, wt;
        cout<<"Edge : ";
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    
    int parent[n];
    int key[n];
    bool mstSet[n];

    for(int i = 0; i < n; i++){
        parent[i] = -1;
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    priority_queue<pair<int, int>, vector<int, int>, greater<pair<int, int >> > pq;

    key[0] = 0;
    pq.push({0, 0});
    for(int i = 0; i < n - 1; i++){
        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;

        for(auto it:adj[u]){
            int v = it.first;
            int weight = it.second;
            if(mstSet[v]==false && weight < key[v]){
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    for(int i = 0; i < n - 1; i++){
       cout << parent[i]<<" ";
    }



    return 0;
}