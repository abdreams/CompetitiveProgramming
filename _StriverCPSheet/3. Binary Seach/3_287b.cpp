#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;


int sum(int n){
	return (n * (n+1)) / 2;
}


int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

	int n, k;
	cin>>n>>k;
    n-=1;
    int s=sum(k-1);
    if(s<n)
        cout<<-1<<endl;
    else{
        int l=0;
        int ans=0;
        int h=k-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(s-sum(mid)>=n) {
                l=mid+1;
                ans=mid;
            }
            else h=mid-1;
        }
        cout<<ans;
    }

 	return 0;
}