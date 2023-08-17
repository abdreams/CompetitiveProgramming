#include<bits/stdc++.h>

using namespace std;

void filterChars(int n,char a[]){
    int j=0;

    while(n>0){
        int last_bit=(n&1);
        if(last_bit==1){
            cout<<a[j];
        }
        j++;
        n=n>>1;
    }
    cout<<endl;
}

void generate_n(char a[]){

    int n=strlen(a);
    for(int i=0;i< (1<<n);i++){
        filterChars(i,a);
    }
    return;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    char a[100];
    cin>>a;

    generate_n(a);

    return 0;
}
