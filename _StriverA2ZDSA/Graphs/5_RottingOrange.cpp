//https://www.codingninjas.com/studio/problems/rotting-oranges_701655?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
#include <bits/stdc++.h>
using namespace std;

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            }
        }
    }
    
    int delR[] = {-1, 0, 1, 0};
    int delC[] = {0, -1, 0, 1};
    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        bool rottenThisRound = false; 
        
        for (int i = 0; i < size; i++) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;

            for (int j = 0; j < 4; j++) {
                int nx = x + delR[j];
                int ny = y + delC[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    rottenThisRound = true;
                    q.push({nx, ny});
                }
            }
        }
        
        if (rottenThisRound) {
            time++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }

    return time;
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxTime=0,freshOrange=0;

        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    // vis[i][j]=2;
                }
                 if(grid[i][j]==1) {
                    freshOrange++;
                 }
            }
        }

      vector<int>delRow={-1,0,+1,0};
      vector<int>delCol={0,-1,0,+1};


    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();
        maxTime=max(maxTime,time);

        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m and grid[row][col]==2 and grid[nrow][ncol]==1){
           
                 grid[nrow][ncol]=2;
                q.push({{nrow,ncol},time+1});
                freshOrange--;
            }
        }
    }
     if(freshOrange!=0){
        return -1;
     }
    
    return maxTime;
    }

};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    cout << minTimeToRot(grid, n, m) << endl;
    
    return 0;
}
