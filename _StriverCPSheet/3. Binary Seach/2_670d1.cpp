#include<bits/stdc++.h>
#define int long long
using namespace std;

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
