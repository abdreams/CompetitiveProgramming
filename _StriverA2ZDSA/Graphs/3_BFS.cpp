vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int>vis(n,0);
    queue<int>q;
    q.push(0);
    vector<int>bfs;


    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}