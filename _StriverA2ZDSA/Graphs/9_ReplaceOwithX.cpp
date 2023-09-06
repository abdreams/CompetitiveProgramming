//codingninjas.com/studio/problems/replace-‘o’-with-‘x’_630517?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
/*
approach is basically saare O jo bhi hai boundary pe unse dfs traversal karo aur dekho
ki kaunse visit horhe agar vo visit hopare iska mtlab wo hai nahi 4 directionallly x
se surrounded


*/
#include <bits/stdc++.h>

void dfs(int x,int y,vector<vector<int>>&vis,char** arr,int n, int  m){
    vis[x][y]=1;
    vector<int>delx={-1,0,1,0};
    vector<int>dely={0,-1,0,1};

    for(int i=0;i<4;i++){
        int nx=x+delx[i];
        int ny=y+dely[i];

        if(nx>=0 and ny>=0 and nx<n and ny<m and !vis[nx][ny] and arr[nx][ny]=='O'){
            dfs(nx, ny, vis, arr, n, m);
        }
    }
}

void replaceOWithX(char** arr, int n, int  m)
{
    //Write your code here   
    vector<vector<int>>vis(n,vector<int>(m,0));

    for(int i=0;i<m;i++){
        if(arr[0][i]=='O' and !vis[0][i]){
            dfs(0, i, vis, arr, n, m);
        }
        if(arr[n-1][i]=='O' and !vis[n-1][i]){
            dfs(n-1, i, vis, arr, n, m);
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i][0]=='O' and !vis[i][0]){
            dfs(i, 0, vis, arr, n, m);
        }
        if(arr[i][m-1]=='O' and !vis[i][m-1]){
            dfs(i, m-1, vis, arr, n, m);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] and arr[i][j]=='O') arr[i][j]='X';
        }
    }

}

