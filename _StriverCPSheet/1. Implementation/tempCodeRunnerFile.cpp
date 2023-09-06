#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string inhand;
    cin>>inhand;
    int flag=-1;

    vector<string>cards_on_table(5);
    for(int i=0;i<5;i++)
         cin>>cards_on_table[i];

    for(auto it:cards_on_table){
        int found = it.find(inhand[0]);
        flag=1;
    }

    for(auto it:cards_on_table){
        int found = it.find(inhand[1]);
        flag=1;
    }

    if(flag==1){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }


    return 0;
}
