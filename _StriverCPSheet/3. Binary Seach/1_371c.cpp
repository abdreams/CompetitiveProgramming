#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(int i, int b_req,int s_req,int c_req, int n_b, int n_s,int n_c, int p_b, 
int p_s, int p_c, int r){
    int nb_=b_req*i-n_b;
    int ns_=s_req*i-n_s;
    int nc_=c_req*i-n_c;

    if(nb_<0) nb_=0;
    if(nc_<0) nc_=0;
    if(ns_<0) ns_=0;

    int pb_=nb_*p_b;
    int pc_=nc_*p_c;
    int ps_=ns_*p_s;

    int total=pb_+pc_+ps_;

    if(total<=r) return true;
    return false;

}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string s;
    cin>>s;

    int n_b,n_c,n_s;
    cin>>n_b>>n_s>>n_c;
    int p_b,p_c,p_s;
    cin>>p_b>>p_s>>p_c;

    int r;
    cin>>r;

    int b_req=0;
    int c_req=0;
    int s_req=0;

    for(int i=0;i<s.length();i++){
        if(s[i]=='B') b_req++;
        if(s[i]=='S') s_req++;
        if(s[i]=='C') c_req++;
    }
    int ans=0;

    int left=0;
    int right=1e14;

    while(left<=right){
        int mid=left+(right-left)/2;
        if(check(mid,b_req,s_req,c_req,n_b,n_s,n_c,p_b,p_s,p_c,r)){
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