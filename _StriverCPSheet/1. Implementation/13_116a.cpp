#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t;
    cin>>t; 
    int curr_in_train=0;
    int seats=INT_MIN;
    while(t--){
        int got_off,got_in;
        cin>>got_off>>got_in;
        curr_in_train=curr_in_train-got_off+got_in;
        seats=max(seats,curr_in_train);
    }
    cout<<seats<<endl;

    return 0;
}
