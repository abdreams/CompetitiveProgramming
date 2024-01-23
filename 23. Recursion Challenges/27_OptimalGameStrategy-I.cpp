// semper fi //
// abdreams //
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define w(x)            int x; cin>>x; while(x--)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int32_t main(){
ab_d();
    deque<int> dq;
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        dq.push_back(arr[i]);   
    }
    int piyush=0;
    int nimit=0;
    while (!dq.empty())
    {
        int fr=dq.front();
        int bk=dq.back();
        if(fr>=bk){
            piyush+=fr;
            dq.pop_front();
        }
        else{
            piyush+=bk;
            dq.pop_back();
        }

        int fr2=dq.front();
        int bk2=dq.back();
        if(fr2<bk2){
            nimit+=fr;
            dq.pop_front();
        }
        else{
            nimit+=bk;
            dq.pop_back();
        }

    }
    cout<<piyush<<endl;
    

    return 0;
}
