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
    int count=0;
    int maxi=0;

    for(int i=0;i<n-1;i++){
        if(arr[i+1]>arr[i]) {
            count++;
            maxi=max(maxi,count);
        }
        else count=0;
    }

    cout<<maxi+1<<endl;


    return 0;
}
