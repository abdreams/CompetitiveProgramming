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

void findMinPath(int start[], int end[], int pipelines[][5], int numPipelines, bool visited[], int currentIndex, bool isReversed, int currentTime) {
    if (isReversed) {
        currentTime += abs(start[0] - end[0]) + abs(start[1] - end[1]);
        minTime = min(minTime, currentTime);
        return;
    }
    if (currentIndex == numPipelines) {
        currentTime += abs(start[0] - end[0]) + abs(start[1] - end[1]);
        minTime = min(minTime, currentTime);
        return;
    }

    for (int i = 0; i < numPipelines; i++) {
        if (!visited[i]) {
            visited[i] = true;
            int travelTime = abs(start[0] - pipelines[i][0]) + abs(start[1] - pipelines[i][1]);
            int tempX = start[0];
            int tempY = start[1];
            start[0] = pipelines[i][2];
            start[1] = pipelines[i][3];
            findMinPath(start, end, pipelines, numPipelines, visited, currentIndex + 1, isReversed, currentTime + travelTime + pipelines[i][4]);
            visited[i] = false;
            start[0] = tempX;
            start[1] = tempY;

            visited[i] = true;
            travelTime = abs(start[0] - pipelines[i][2]) + abs(start[1] - pipelines[i][3]);
            tempX = start[0];
            tempY = start[1];
            start[0] = pipelines[i][0];
            start[1] = pipelines[i][1];
            findMinPath(start, end, pipelines, numPipelines, visited, currentIndex + 1, isReversed, currentTime + travelTime + pipelines[i][4]);
            visited[i] = false;
            start[0] = tempX;
            start[1] = tempY;
        }
    }
    findMinPath(start, end, pipelines, numPipelines, visited, currentIndex + 1, !isReversed, currentTime);
    return;
}

int main() {
ab_d();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int start[2], end[2];
        int numPipelines;
        cin >> numPipelines;
        cin >> start[0] >> start[1] >> end[0] >> end[1];
        int pipelines[5][5];
        bool visited[5];
        for (int j = 0; j < numPipelines; j++) {
            cin >> pipelines[j][0] >> pipelines[j][1] >> pipelines[j][2] >> pipelines[j][3] >> pipelines[j][4];
            visited[j] = false;
        }

        findMinPath(start, end, pipelines, numPipelines, visited, 0, false, 0);
        cout << "#" << i << " : " << minTime << endl;
        minTime = INT_MAX;
    }
    return 0;
}
