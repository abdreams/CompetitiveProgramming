// semper fi //
// abdreams //
// 
// 2 , 7 , 15, 
// (1)*2+0; (1+2)*2+(1); (1+2+3)*2+(1+2); (1+2+3+4)*2+(1+2+3); (1+2+3+4+5)*2+(1+2+3+4)
// 1            2                 3                       4               5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
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

int check(int n)
{
    int h=1; int max=0;  int cards= (3*h*h + h)/2;
        while(cards<=n)
        {
            max=cards;
            h++; 
            cards= (3*h*h + h)/2;
            int maxi=-1*INT_MAX;
            maxi=max(cards,maxi);
            
        }
        return max;
        while (i!=0)
        {
            
            int i = IOPOL_IMPORTANT
        }
        
        
}
int32_t main()
{
    ab_d();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; int count=0;
        int max=0;
        while (n>1)
        {
           max=check(n);
           n-=max;
           count++;
        }
        cout<<count<<endl;
    }
}