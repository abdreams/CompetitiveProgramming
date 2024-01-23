#include <bits/stdc++.h>
using namespace std;
#define int long long

void ab_d() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n, m;
vector<vector<int>> grid;
vector<vector<int>> vis;

void dfs(int i, int j, int& count) {
    vis[i][j] = 1;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 and ni < n and nj >= 0 and nj < m and !vis[ni][nj] and grid[ni][nj]) {
            vis[ni][nj] = 1;
            count++;
            dfs(ni, nj, count);
            // vis[ni][nj]=0;
        }
    }
}

int32_t main() {
    ab_d();
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    vis.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int max_pond_size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                vis.assign(n, vector<int>(m, 0));
                grid[i][j] = 1;
                int count = 1;
                dfs(i, j, count);
                max_pond_size = max(max_pond_size, count);
                grid[i][j] = 0;
            }
        }
    }

    cout << max_pond_size << endl;

    return 0;
}
