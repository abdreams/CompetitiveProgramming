#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define w(x)            int x; cin>>x; while(x--)
#define dbg             cout<<"iishtea"<<endl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void FAST_IO(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
    string burger;
    int n_b,n_s,n_c;
    int p_b,p_s,p_c;
    int r;
    int n_b_rqd,n_s_rqd,n_c_rqd;

bool check(int i){
    int nb_=n_b_rqd*i-n_b;
    if(nb_<0) nb_=0;
    int ns_=n_s_rqd*i-n_s;
    if(ns_<0) ns_=0;
    int nc_=n_c_rqd*i-n_c;
    if(nc_<0) nc_=0;


    int moneyreqd=(nb_*p_b)+(ns_*p_s)+(nc_*p_c);
    if(moneyreqd<=r) return true;
    return false;    
}
int32_t main(){
FAST_IO();
    cin>>burger;
    cin>>n_b>>n_s>>n_c;
    cin>>p_b>>p_s>>p_c;
    cin>>r;

    for (auto &&it : burger)
    {
        if(it=='B') n_b_rqd++;
        else if(it=='S') n_s_rqd++;
        else n_c_rqd++;
    }


    int ans=0;
    int left=0;
    int right=1e14;

    while (left<=right)
    {
        int mid=(left)+(right-left)/2;
        if(check(mid)){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    
    cout<<ans<<endl;
    dbg
    return 0;
}