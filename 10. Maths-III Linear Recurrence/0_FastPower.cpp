#include<bits/stdc++.h>

using namespace std;

double faspow(double n,int p){
    if(p==1) return n;

    if(p%2==1) return n*faspow(n,p/2)*faspow(n,p/2);
    return faspow(n,p/2)*faspow(n,p/2);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    double n;
    int p;
    cin>>n>>p; 

    if(p<0){
        p=abs(p);
        n=1/n;
    }

    cout<<faspow(n,p)<<endl;

}
