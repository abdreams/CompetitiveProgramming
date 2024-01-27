#include <bits/stdc++.h>
using namespace std;

#define int long long

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}


int search(vector<int>arr, int l, int h, int key) {
    if (l > h) return -1; 

    int mid = (l + h)>>2; 
    if (arr[mid] == key) return mid; 

    if (arr[l] <= arr[mid]) { 
        if (key >= arr[l] && key <= arr[mid]) return search(arr, l, mid - 1, key); 
        return search(arr, mid + 1, h, key); 
    } 

    if (key >= arr[mid] && key <= arr[h]) return search(arr, mid + 1, h, key); 

    return search(arr, l, mid - 1, key); 
}


int32_t main(){
ab_d();
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int tobesearched;
    cin>>tobesearched;

    cout<<search(arr,0,n-1,tobesearched)<<endl;

    return 0;
}
