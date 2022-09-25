class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */

    bool dfs(int u,int par,vector<bool>&vis,vector<vector<int>>&adj)
    {
        vis[u]=true;
        for(auto v:adj[u]){
            if(vis[v]==false){
                if(dfs(v,u,vis,adj))
                {
                    return true;
                }
                
            }
            else{
                if(par!=v){
                    return true;
                }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int count=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                count++;
                if(dfs(i,-1,vis,adj))
                {
                   return false;
                }
            
            }
            
        }
        if(count>1){
                return false;
            }
        return true;
    }
};
