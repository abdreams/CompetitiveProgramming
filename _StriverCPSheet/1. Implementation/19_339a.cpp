#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string s;
    cin>>s; 

    vector<char>elements;
   
    for(auto it:s){
        if(it=='1'){
            elements.push_back(it);
        }
        else if(it=='2') {
            elements.push_back(it);

        }
        else if(it=='3'){
            elements.push_back(it);
        }
   
    }

    sort(elements.begin(),elements.end());

    for(int i=0;i<elements.size()-1;i++){
        cout<<elements[i]<<"+";
    }
    cout<<elements[elements.size()-1];

    return 0;
}
