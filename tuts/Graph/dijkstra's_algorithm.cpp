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

void dijkstraShortestPath(int N, vector<pair<int, int>> adj[], int src){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N+1, INT_MAX);
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while(!pq.empty()){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>>:: iterator it;
        for(auto it:adj[prev])
            {
                int next = it.first;
                int nextDist = it.second;
                if(dist[prev] + nextDist < dist[next]) 
                    {
                        dist[next] =  dist[prev] + nextDist;
                        pq.push(make_pair(dist[next], next));
                    }
            }
    }
    for(int i = 0; i < N; i++){
        cout << dist[i] << " ";
    }
}

int main()
{
    int n, m, src;
    cin >> n >> m;
    vector<pair<int, int>> adj[n+1];

    for(int i = 0; i < m; i++){
        int u, v, wt;
        cout<<"Edge : ";
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    cin >> src;
    dijkstraShortestPath(n, adj, src);
    return 0;
}