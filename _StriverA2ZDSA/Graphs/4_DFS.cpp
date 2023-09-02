void dfs(int node,int par,vector<vector<int>>&adj,vector<int>&vis,vector<int>&dfss){
    vis[node]=1;
    dfss.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            vis[it]=1;
            dfs(it, node, adj, vis,dfss);
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>>adj(V);

    for(auto it:edges){
        int par=it[0];
        int neighbour=it[1];
        adj[par].push_back(neighbour);
        adj[neighbour].push_back(par);
    }

    vector<int>vis(V,0);
    vector<vector<int>>ans;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int>dfss;
            dfs(i,-1,adj,vis,dfss);
            ans.push_back(dfss);

        }
    }
    return ans;
}