int matrixTraps(int n, int m, vector<vector<int>>& matrix) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    int total_Zeros = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                total_Zeros++;
            }
        }
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int i = 0; i < m; i++) {
        if (matrix[0][i] == 0 && !vis[0][i]) {
            q.push({0, i});
            vis[0][i] = 1;
            total_Zeros--;
        }
        if (matrix[n - 1][i] == 0 && !vis[n - 1][i]) {
            q.push({n - 1, i});
            vis[n - 1][i] = 1;
            total_Zeros--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0 && !vis[i][0]) {
            q.push({i, 0});
            vis[i][0] = 1;
            total_Zeros--;
        }
        if (matrix[i][m - 1] == 0 && !vis[i][m - 1]) {
            q.push({i, m - 1});
            vis[i][m - 1] = 1;
            total_Zeros--;
        }
    }

    while (!q.empty()) {
        auto it = q.front();
        int x = it.first;
        int y = it.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && matrix[nx][ny] == 0 
            && !vis[nx][ny]) {
                total_Zeros--;
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
    return total_Zeros;
}