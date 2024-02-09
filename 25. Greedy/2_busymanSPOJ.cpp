#include <bits/stdc++.h>
using namespace std;

#define int long long

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int32_t main(){
    ab_d();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>arr(n,vector<int>(2,-1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j>=0; j--)
            {
                cin>>arr[i][j];
            }
        }

        sort(arr.begin(),arr.end());
        

        int act=0;
        int lastendTime=-1;
        for (int i = 0; i < n; i++)
        {

            int startTime = arr[i][1];
            int endTime = arr[i][0];

            if(lastendTime==-1){
                lastendTime=endTime;
                act++;
            }
            if(startTime>=lastendTime){
                act++;
                lastendTime=endTime;
            }


        }

        cout<<act<<endl;
    }

    return 0;
}
