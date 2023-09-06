//https://www.codingninjas.com/studio/problems/detect-cycle-in-an-undirected-graph-_758967?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// bfs
class Graph {
public:
    bool isCycleUtil(int node, int parent, vector<int>& vis, vector<int> adj[]) {
        queue<pair<int, int>> q;
        q.push({node, parent});
        vis[node] = 1;
        
        while (!q.empty()) {
            auto x = q.front();
            int currentNode = x.first;
            int currentParent = x.second;
            q.pop();
            
            for (auto neighbour : adj[currentNode]) {
                if (!vis[neighbour]) {
                    vis[neighbour] = 1;
                    q.push({neighbour, currentNode});
                } else if (neighbour != currentParent) {
                    return true;
                }
            }
        }
        
        return false;
    }

    bool detectCycle(int V, vector<int> adj[]) {
        vector<int> vis(V , 0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycleUtil(i, -1, vis, adj)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
//dfs
class Graph {

public:
bool dfs(int node,int parent,vector<int> adj[],vector<int>& vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it]==0){
          if (dfs(it,node,adj,vis)) return true;
        }
        else if(it!=parent)
          return true;
    }
    return false;
}
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(dfs(i,-1, adj, vis)) return true; 
            }
        }
        return false; 
    }
    
};