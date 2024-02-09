// C++ Code
#include <bits/stdc++.h>
using namespace std;
#define MAX 50000000000
#define int long long int
int dp[5005][5005];

int valentine(vector<int> &choc,vector<int> &candy,int i,int j){
    if(i == choc.size()){
        return 0 ;
    }
    if(j == candy.size()){
        return INTMAX_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int diff = abs(choc[i] - candy[j]) ;
    int q1 = valentine(choc,candy,i+1,j+1) + diff;    
    int q2 = valentine(choc,candy,i,j+1) ;                  

    return dp[i][j] = min(q1,q2);
 
}

int main() {
    int n ; //No of boys
    int m ; //No of girls
    cin >> n >> m;
    vector<int> choc;
    vector<int> candy;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        choc.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        candy.push_back(x);
    }

    memset(dp,-1,sizeof(dp));

    sort(choc.begin(),choc.end());
    sort(candy.begin(),candy.end());

    cout << valentine(choc,candy,0,0) ;


    return 0;
}