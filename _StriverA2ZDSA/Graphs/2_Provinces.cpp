//https://www.codingninjas.com/studio/problems/find-the-number-of-states_1377943?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (roads[i][j] == 1 && i != j) {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> vis(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans++;
            dfs(i, adj, vis);
        }
    }
    return ans;
}
