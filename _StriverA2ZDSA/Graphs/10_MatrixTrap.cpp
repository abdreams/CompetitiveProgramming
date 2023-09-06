//https://www.codingninjas.com/studio/problems/matrix-traps_8365440?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int matrixTraps(int n,int m,vector<vector<int>> &matrix)
{
    // Write your code here.
    vector<vector<int>>vis(n,vector<int>(m,0));

    queue<pair<int,int>>q;
    int total_Zeros=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                total_Zeros++;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(matrix[0][i]==0 and !vis[0][i]) {
            q.push({0, i});
            vis[0][i]=1;
        }
        if(matrix[n-1][i]==0 and !vis[n-1][i]) {
            q.push({n - 1, i});
            vis[n-1][i]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(matrix[i][0]==0 and !vis[i][0]) {
            q.push({0, i});
            vis[i][0]=1;
        }
        if(matrix[i][m-1]==0 and !vis[i][m-1]) {
            q.push({i, m - i});
            vis[i][m-1]=1;
        }
    }
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};

    while(!q.empty()){
        auto it=q.front();
        int x=it.first;
        int y=it.second;
        vis[x][y]=1;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 and ny>=0 and nx<n and ny<m and matrix[nx][ny]==0 and
            !vis[nx][ny]){
                total_Zeros--;
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
        }
    }
    return total_Zeros;

}