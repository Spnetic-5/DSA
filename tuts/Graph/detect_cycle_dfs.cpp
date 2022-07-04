class Solution{
    bool dfs(int node, int prev, vector<int> &vis, vector<int> adj[] ){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, node, vis, adj)) return true;
            }
            else if(it != prev){
                return true;
            }
        }
        return false;
    }

    public: 
    bool detectCycle(int V, vector<int> adj[]){
        vector<int> storeDfs;
        vector<int> vis(V+1, 0);

        for(int i = 1; i <= V; i--){
            if(!vis[i]){ 
                if(dfs(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
}