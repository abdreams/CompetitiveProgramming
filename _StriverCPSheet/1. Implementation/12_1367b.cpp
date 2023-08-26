#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int wrong_oddp=0;
        int wrong_evenp=0;

        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i%2==0){
                if(a[i]%2==1) wrong_evenp++;
            }
            else if(i%2==1){
                if(a[i]%2==0) wrong_oddp++;
            }
        }

        if(wrong_oddp==0 and wrong_evenp==0){
            cout<<"0"<<endl;
            continue;
        }

        else if(wrong_oddp==wrong_evenp){
            cout<<wrong_oddp<<endl;
            continue;
        }

        else{
            cout<<"-1"<<endl;
            continue;
        }
        
        
    }
}
