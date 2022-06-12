class Solution{
    void dfs(int node, vector<int> &vis, vector<int> &storeDfs, vector<int> adj[] ){
        storeDfs.push_back(node);
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, storeDfs, adj);
            }
        }
    }

    public: 
    vector<int>dfsOfGraph(int V, vector<int> adj[]){
        vector<int> storeDfs;
        vector<int> vis(V+1, 0);

        for(int i = 1; i <= V; i--){
            if(!vis[i]){
                dfs(i, vis, storeDfs, adj);
            }
        }

    }
}