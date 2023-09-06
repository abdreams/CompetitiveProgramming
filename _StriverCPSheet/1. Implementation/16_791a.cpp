#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int wt_l,wt_b;
    cin>>wt_l>>wt_b; 
    int count=0;
    if(wt_l==wt_b){
        cout<<"1"<<endl;
        return 0;
    }
    else {
        while(wt_l<=wt_b){
            wt_l*=3;
            wt_b*=2;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
