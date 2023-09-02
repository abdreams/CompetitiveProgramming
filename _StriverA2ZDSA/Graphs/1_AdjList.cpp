//https://www.codingninjas.com/studio/problems/creating-and-printing_1214551?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=3

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.

    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        adj[i].push_back(i);
    }

    for(auto it:edges){
        int parent=it[0];
        int neighbour_node=it[1];
        adj[parent].push_back(neighbour_node);
        adj[neighbour_node].push_back(parent);
    }
    return adj;
}
