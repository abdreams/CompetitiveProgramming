// to solve equations of the form Ax+By=(A%B)

#include<bits/stdc++.h>

using namespace std;

int x,y,GCD;

void extedned_euclids(int a,int b){
    if(b==0){
        x=1;
        y=0;
        GCD=a;
        return;
    }
    extedned_euclids(b,a%b);
    int cX=y;
    int cY=x-(a/b)*y;

    x=cX;
    y=cY;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int a,b;
    cin>>a>>b;

    extedned_euclids(a,b);

    cout<<x<<" "<<y<<endl;
    return 0;
}
