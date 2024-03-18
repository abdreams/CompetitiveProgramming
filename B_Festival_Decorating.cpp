
int dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    int size = 1;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            size += dfs(neighbor, graph, visited);
        }
    }

    return size;
}

int journeyToMoon(int n, vector<vector<int>>& astronaut) {
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    for (auto& pair : astronaut) {
        graph[pair[0]].push_back(pair[1]);
        graph[pair[1]].push_back(pair[0]);
    }

    long long result = 0;
    long long totalNodes = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            long long size = dfs(i, graph, visited);
            result += totalNodes * size;
            totalNodes += size;
        }
    }

    return result;
}