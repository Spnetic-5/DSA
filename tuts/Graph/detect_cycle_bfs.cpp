class Solution{

public: 
    bool checkForCycle(int s, int V, vector<int> &vis, vector<int> adj[]){
        queue<pair<int,int>> q;
        vis[s] = 1;
        q.push({s, -1});

        while(!q.empty()){
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();

            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push({it, node});
                    vis[it] = 1;
                }
                else if(it != prev)
                {
                    return true;
                }
            }
        }
        return true;
    }

public:
    bool isCycle(int V, vector<int> adj[]){
        vector<int> vis(V+1, 0);
        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                if(checkForCycle(i, V, vis, adj)) return true;
            }
        }
        return false;
    }
}