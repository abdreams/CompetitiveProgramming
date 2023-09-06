//https://www.codingninjas.com/studio/problems/distance-of-nearest-cell-having-1-in-a-binary-matrix_1169913?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
vector < vector < int > > nearest(vector < vector < int >> & mat, int n, int m) {
    // Write your code here.
    vector<vector<int>>ans(n,vector<int>(m,-1));

    queue<pair<pair<int, int>, int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                ans[i][j]=0;
                q.push({{i,j},0});
            }
        }
    }

    while(!q.empty()){
        auto element=q.front();
        int x=element.first.first;
        int y=element.first.second;
        int distance=element.second;
        q.pop();

        vector<int>delx={-1,0,1,0};
        vector<int>dely={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nx=x+delx[i];
            int ny=y+dely[i];

            if(nx>=0 and ny>=0 and nx<n and ny<m){
                if(ans[nx][ny]==-1 or distance+1<ans[nx][ny]){
                    ans[nx][ny]=1+distance;
                    q.push({{nx,ny},ans[nx][ny]});
                }
            }
        }
    }

    return ans;

}