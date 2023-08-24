#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n,m;
    cin>>n>>m; 
    int x=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==0) cout<<"#";
            
            else{
                if(x==1){
                
                if(j==m-1) cout<<"#";
                else cout<<".";
                
                }
                else{
                    if(j==0) cout<<"#";
                    else cout<<".";
                    
                }
                
            }
        }cout<<endl;
         if (i % 2 == 1) {
            x = !x;
        }
        
    }
}
