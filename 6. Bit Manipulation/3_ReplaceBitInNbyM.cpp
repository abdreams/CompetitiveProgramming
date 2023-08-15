#include<bits/stdc++.h>

using namespace std;

int clearRangeItoJ(int n,int i,int j){
    //j>i assumed
    int a=-1<<(j+1);
    int b=(1<<i)-1;
    int mask= a|b;
    return n&mask;

}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n,m,i,j;
    cin>>n>>m>>i>>j; 

    int cleared_num =clearRangeItoJ(n,i,j);

    int shifted_num= m<<i;

    cout<<cleared_num<<" "<<shifted_num<<endl;

    cout<< (cleared_num | shifted_num) <<endl;

    return 0;
}
