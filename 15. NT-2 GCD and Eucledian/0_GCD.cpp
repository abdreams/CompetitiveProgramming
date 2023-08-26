//https://hack.codingblocks.com/app/practice/1/1040/problem

#include<bits/stdc++.h>
// visualize b aur a ko divide karne wala tareeka 
using namespace std;

int calculate_gcd(int a,int b){

    if(b==0) return a;
    else return calculate_gcd(b,a%b);

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int a,b;
    cin>>a>>b; 

    cout<<calculate_gcd(a,b)<<endl;

    return 0;
}
