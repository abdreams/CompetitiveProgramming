#include<bits/stdc++.h>

using namespace std;
int x,y,GCD;

int calculate_gcd(int a,int b){

    if(b==0) return a;
    else return calculate_gcd(b,a%b);

}

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
    int n,p,w,d;
    cin>>n>>p>>w>>d;

    int gcd_nums=calculate_gcd(w,d);

    if(p%gcd_nums!=0) {
        cout<<-1<<endl;
        return 0;
    }

    extedned_euclids(w,d);
    cout<<x<< " "<<y<<endl;


    return 0;
}
