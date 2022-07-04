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

bool isCyclic(int N, vector<int> adj[]){
    queue<int> q;
    vector<int> indeg(N+1, 0);

    for(int i = 0; i < N; i++){
        for(auto it:adj[i]){
            indeg[it]++;
        }
    }

    for(int i = 0; i < N; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for(auto it: adj[node]){
            indeg[it]--;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }
    if(count == N) return false;
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
    }

    vector<int> ans;
    ans = isCyclic(n, adj);
    cout<<ans<<endl;
    return 0;
}