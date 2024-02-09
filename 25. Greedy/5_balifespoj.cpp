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
    bool f=true;
    while (f)
    {   int n;
        cin>>n;
        if(n==-1){
            f=false;
            return 0;

        }
        vector<int>arr(n,0);
        int avg=0;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            avg+=arr[i];
        }
        if(avg%n!=0){
            cout<<-1<<endl;
        }
        else{
            int diff=0;
            int maxi=INT_MIN;
            avg=avg/n;
            for (int i = 0; i < n; i++)
            {
                diff+=(arr[i]-avg);
                maxi=max(maxi,abs(diff));
            }
            cout<<maxi<<endl;
        }
    }
    

    return 0;
}