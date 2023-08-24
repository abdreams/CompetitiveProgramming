#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    int faces=0;
    while(n--){
        string shape;
        cin>>shape;
        if(shape=="Tetrahedron"){
            faces+=4;
        }
        else if(shape=="Cube"){
            faces+=6;
        }
        else if(shape=="Octahedron"){
            faces+=8;
        }
        else if(shape=="Dodecahedron"){
            faces+=12;
        }
        else if(shape=="Icosahedron"){
            faces+=20;
        }
    }
    cout<<faces<<endl;
}
