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
        int temp=n;

        if(n>=1 and n<=9){
            cout<<1<<endl;
            cout<<n<<endl;
            continue;
        }

        else{
            int count=0;
            int cnt=0;
            while(temp!=0){
                int tmp=temp%10;
                if(tmp!=0){
                    cnt++;
                }
                temp=temp/10;
            }
            cout<<cnt<<endl;
            
            while(n!=0){
                int tmp=n%10;
                if(tmp!=0){
                    cout<<(pow(10,count)*tmp)<<endl;;
                }
                count++;
                n=n/10;
            }
        }
    }
}
