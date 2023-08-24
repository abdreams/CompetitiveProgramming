#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int pt1,pt2,pt3;
    cin>>pt1>>pt2>>pt3;

    int dist_to_pt1=abs(pt2-pt1)+abs(pt3-pt1);
    int dist_to_pt2=abs(pt3-pt2)+abs(pt1-pt2);
    int dist_to_pt3=abs(pt3-pt1)+abs(pt3-pt2);

    cout<<min(dist_to_pt1,min(dist_to_pt2,dist_to_pt3))<<endl;
}
