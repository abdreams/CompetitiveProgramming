#include<bits/stdc++.h>

using namespace std;

void multiplybig(vector<int>&arr,int &num,int i){
    int carry=0;
    for (int j = 0; j < num; j++)
    {
        int product=arr[j]*i+carry;
        arr[j]=product%10;
        carry=product/10;
    }

    while (carry)
    {
        arr[num]=carry%10;
        carry=carry/10;
        num++;
    }
}

void bigfact(int n){
    vector<int>arr(1000,0);

    arr[0]=1;
    int num=1;
    for(int i=2;i<=n;i++){
        multiplybig(arr,num,i);
    }

    for (int k = n-1; k >=0; k--)
    {
        cout<<arr[k];
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n; 
    bigfact(n);
    
}
