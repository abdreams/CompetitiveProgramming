//https://www.codingninjas.com/studio/problems/distinct-islands_630460?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
#include <vector>
#include <set>

void dfs(int x,int y,vector<vector<int>>&vis,int** arr,int n,int m,int x0,int y0,
vector<pair<int,int>>&vec){
    
    vis[x][y]=1;

    vec.push_back({x-x0,y-y0});

    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};

    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0 and ny>=0 and nx<n and ny<m and !vis[nx][ny] 
        and arr[nx][ny]==1 )
        {
            dfs(nx, ny, vis, arr, n, m, x0, y0, vec);
        }
    }

}

int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    vector<vector<int>>vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>>st;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] and arr[i][j]==1){
                vector<pair<int,int>>vec;
                dfs(i, j, vis, arr, n, m, i, j, vec);
                st.insert(vec);
            }
        }
    }
    return st.size();

}