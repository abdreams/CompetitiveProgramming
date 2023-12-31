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

int multiplicative_modulo_inverse(int a,int m){
    extedned_euclids(a,m);
    return (x+m)%m;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cout<<multiplicative_modulo_inverse(18,7)<<endl; //  18*'2' % 7 ==1
    cout<<multiplicative_modulo_inverse(6,7)<<endl; // 6*'6' % 7 ==1

    //note that there only exists a modulo inv iff gcd of both nums is 1.

    return 0;
}
