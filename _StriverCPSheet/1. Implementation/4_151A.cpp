/*
To make a toast, each friend needs nl milliliters of the drink, a slice of lime and np grams of salt. The friends want to make as many toasts as they can, provided they all drink the same amount. How many toasts can each friend make?

Input
The first and only line contains positive integers n, k, l, c, d, p, nl, np, not exceeding 1000 and no less than 1. The numbers are separated by exactly one space.

Output
Print a single integer — the number of toasts each friend can make.*/

#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int total_drink=k*l;
    int total_toasts=(total_drink)/nl;
    int lime_slices=c*d;
    int salt_toast=p/np;

    cout<<(min(total_toasts,min(lime_slices,salt_toast)))/n<<endl;
    
}
