#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string s;
    cin>>s; 
    
    //a=97
    //A=65
    if(s[0]>='A' and s[0]<='Z'){
        cout<<s<<endl;
        return 0;
    }
    else{
     s[0]=s[0]-32;
    }

    cout<<s<<endl;

    return 0;
}
