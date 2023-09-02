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
    string s1, s2; 
    cin >> s1 >> s2; 
    
    if (s1[0] != s2[0] && s1[s1.size() - 1] != s2[s2.size() - 1]) 
    { 
    cout << "NO" << endl; 
    
    } 
    
    if (s1[0] == s1[s1.size() - 1] && s2[0] == s2[s1.size() - 1] && s1[0] == s2[0]) 
    { 
        cout << "YES" << endl; 
    
    }
    
    int f = 0; 
    
    for (int i = 0; i < s1.size() - 1; i++) 
    { 
    if (s1[i] == s1[0] && s2[i] == s1[0] && s1[i + 1] == s2[i + 1] && s1[i + 1] == s1[s1.size() - 1]) 
    f = 1; 
    } 
    
    if (f == 0) 
    cout << "NO" << endl; 
    else 
    cout << "YES" << endl; 
    }
    

    return 0;
}
