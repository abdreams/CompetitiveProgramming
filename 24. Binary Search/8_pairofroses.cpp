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
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n,0);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int money;
        cin>>money;
        int p1,p2;

        sort(arr.begin(),arr.end());

        for (int i = 0; i < n/2; i++)
        {
            if(arr[i]>=money) continue;
            else{
                int bacha_hua=money-arr[i];
                bool present=binary_search(arr.begin()+n/2,arr.end(),bacha_hua);
                if(present){
                    p1=arr[i];
                    p2=bacha_hua;
                }
            }
        }
        
        cout<<p1<<" "<<p2<<endl;
        
    }
    

    return 0;
}
