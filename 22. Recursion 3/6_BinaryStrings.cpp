/*
fine no of strings of lenght n which have no consecutive 1s
*/
// https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include<bits/stdc++.h>
using namespace std;

int solve(int n, bool one_status){
        if(n==0) return 1; 
        if(n<0) return 0;
    
        int take_one=0;
    
        if(one_status)
            take_one=solve(n-1,false);
        int take_zero=solve(n-1,true);
    
        return take_one+take_zero;
}

int solve2(int n){
    if(n==2) return 3;
    if(n==1) return 2;

    if(n<0) return 0;

    return solve2(n-1)+solve2(n-2);
    
}



int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n; 
    int ans1=solve(n,true);
    int ans=solve2(n);
    cout<<ans1<<endl;
    cout<<ans<<endl;
    return 0;
}
