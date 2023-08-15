#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n; //no of elements in array
    vector<int>arr;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    // each element in array is two times except for one element we have to find that element

    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
         // we take xor of every element as two same numbers ka xor is 0 (a^a=0)
         // and (0^b=b)
         // toh aise end me wohi number bachega jo ek bar tha!
    }
    cout<<ans<<endl;
    return 0;
}


