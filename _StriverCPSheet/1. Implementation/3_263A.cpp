#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int x=-1;
    int y=-1;
    vector<vector<int>>matrix(5,vector<int>(5,-1));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]==1){
                x=i;
                y=j;
            }
        }
    }

    int moves=abs(x-2)+abs(y-2);
    cout<<moves<<endl;
}
