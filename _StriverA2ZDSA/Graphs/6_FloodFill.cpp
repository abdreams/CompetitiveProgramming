#include <bits/stdc++.h>
using namespace std;
//codingninjas.com/studio/problems/flood-fill-_1082141?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
vector<vector<int>> floodFill(vector<vector<int>> &image, 
int n, int m, int x, int y, int p) {
    // Write your code here.
    int original=image[x][y];
    image[x][y]=p;

    queue<pair<int,int>>q;
    q.push({x,y});

    while(!q.empty()){
        auto it=q.front();
        int x=it.first;
        int y=it.second;
        q.pop();

        vector<int>delR={-1,0,1,0};
        vector<int>delC={0,-1,0,1};

        for(int i=0;i<4;i++){
            int nx=x+delR[i];
            int ny=y+delC[i];
            if(nx>=0 and ny>=0 and nx<n and ny<m and image[nx][ny]==original
            and image[x][y]==p){
                image[nx][ny]=p;
                q.push({nx,ny});
            }
        }

    }
    return image;

}

int main() {
    int n, m;
    cin >> n >> m;  // Input the dimensions of the image matrix

    vector<vector<int>> image(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> image[i][j];  // Input the image matrix
        }
    }

    int x, y, p;
    cin >> x >> y >> p;  // Input x, y coordinates and new pixel value

    vector<vector<int>> result = floodFill(image, n, m, x, y, p);

    // Output the modified image matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//

class Graph {

public:
bool dfs(int node,int parent,vector<int> adj[],vector<int>& vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it]==0){
            if(dfs(it,node,adj,vis)==true)
          return true ;
        }
        else if(it!=parent)
          return true;
    }
    return false;
}
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(dfs(i,-1, adj, vis)) return true; 
            }
        }
        return false; 
    }
    
};
