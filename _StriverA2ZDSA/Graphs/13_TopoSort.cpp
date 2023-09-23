//Kahn's algo:

#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    vector<vector<int>>adj(nodes);
    queue<int>q;
    vector<int>indegree(nodes,0);
    for(auto it:graph){
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }

    for(int i=0;i<nodes;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int>topo;

    while(!q.empty()){
        auto node=q.front();
        q.pop();
        topo.push_back(node);

        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
            
        }
    }
    return topo;

}

// using dfs

#include<bits/stdc++.h>

void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
    vis[node]=1;

    for(auto it:adj[node]){
        if(!vis[it])
            dfs(it,vis,st,adj);
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    vector<vector<int>>adj(nodes);
   
    for(auto it:graph){
        adj[it[0]].push_back(it[1]);
    }
    vector<int>vis(nodes,0);
    stack<int>st;

    for(int i=0;i<nodes;i++){
        if(!vis[i])
            dfs(i,vis,st,adj);
    }

    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    return topo;

}



