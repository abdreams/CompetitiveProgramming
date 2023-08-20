// min number of people that should be present in a hall that there is 50% chance of two people have same bday

#include<bits/stdc++.h>

using namespace std;

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int days=365;
    int people=0;
    double diff_bday_prob=1;
    double same_bday_prob=0;

    double reqd;
    cin>>reqd;

    while(same_bday_prob<=reqd){
        diff_bday_prob*=(days)/365.00;
        days--;
        people++;
        same_bday_prob=1-diff_bday_prob;
    }
    
    cout<<people<<endl;
    cout<<same_bday_prob<<endl;

    return 0;
}
