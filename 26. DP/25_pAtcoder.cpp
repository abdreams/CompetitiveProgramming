#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

const int MOD = 1e9 + 7;

using namespace std;

void solve(int current, int parent, vector<vector<int>>& graph, vector<int>& colors, vector<set<vector<int>>>& ways) {
    for (int color = 0; color <= 1; color++) {
        colors[current] = color;

        if (color != colors[parent]) {
            bool valid = true;

            for (int neighbor : graph[current]) {
                if (colors[neighbor] == color) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                for (int neighbor : graph[current]) {
                    if (neighbor != parent) {
                        solve(neighbor, current, graph, colors, ways);
                    }
                }
            }
        }
    }

    ways[current].insert(colors);
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    vector<int> colors(N + 1, 0);
    vector<set<vector<int>>> ways(N + 1);

    for (int i = 1; i <= N - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    solve(1, 0, graph, colors, ways);

    cout << ways[1].size() << endl;

    return 0;
}
