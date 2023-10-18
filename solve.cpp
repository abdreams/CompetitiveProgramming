#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)        substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x)         cerr<<#x<<": "<<x<<" "<<endl;
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
// // // //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //
bool check(int i,vector<int>&reqd_ingridients,vector<int>ingridients_stock,int k){
    int n=reqd_ingridients.size();

    vector<int>reqd_ingridients_for_i_cookies(n,0);
    
    for(int j=0;j<n;j++){
        reqd_ingridients_for_i_cookies[j]=i*reqd_ingridients[j];
    }

    for(int j=0;j<n;j++){
        reqd_ingridients_for_i_cookies[j]-=ingridients_stock[j];
        if(reqd_ingridients_for_i_cookies[j]<0) reqd_ingridients_for_i_cookies[j]=0;
    }

    int extra_ingridients_needed=0;


    for(auto it:reqd_ingridients_for_i_cookies){
        extra_ingridients_needed+=it;
    }

    if(extra_ingridients_needed<=k) return true;
    return false;

}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n,k;
    cin>>n>>k;

    vector<int>reqd_ingridients(n,0);

    for(int i=0;i<n;i++)
        cin>>reqd_ingridients[i];

    vector<int>ingridients_stock(n,0);

    for(int i=0;i<n;i++)
        cin>>ingridients_stock[i];

    int left=0;
    int right=1e14;
    int ans=0;

    while(left<=right){
        int mid=left+(right-left)/2;

        if(check(mid,reqd_ingridients,ingridients_stock,k)){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }

    }
    cout<<ans<<endl;
    
    return 0;
}

}

int32_t main()
{
    ab_d();

    return 0;
}