bool dfs(int node, int par, int colour, std::vector<int>& colours, std::vector<std::vector<int>>& adj) {
    colours[node] = colour;

    for (auto it : adj[node]) {
        if (colours[it] == -1) {
            if (!dfs(it, node, !colour, colours, adj)) {
                return false;
            }
        } else if (colours[it] == colours[node]) {
            return false;
        }
    }
    return true;
}


bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n=edges.size();
	vector<vector<int>>adj(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(edges[i][j]==1){
				adj[i].push_back(j);
			}
		}
	}
	vector<int>colours(n,-1);

    for (int i = 0; i < n; i++) {
        if (colours[i] == -1) {
            if (!dfs(i, -1, 0, colours, adj)) {
                return false;
            }
        }
    }
    return true;

}

/*
Abhay — Today at 12:03 PM
i had one more doubt, why does this code not work the other way if we return true whenever our dfs fxn is true?
vinitjnnn — Today at 12:04 PM
bcz it does not account for the possibility that there might be multiple connected components in the graph.
Abhay — Today at 12:06 PM
wouldnt that be covered by the last for loop?
vinitjnnn — Today at 12:06 PM
nope
simply returning true after finding that one connected component is bipartite wont work*/