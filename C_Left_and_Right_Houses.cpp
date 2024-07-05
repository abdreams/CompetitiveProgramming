//#pragma comment(linker, "/STACK:2000000")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int>l(2);
        vector<int>r(2);
        l.resize(2,0);
        r.resize(2,0);
        
        for (int i=0;i<n;i++){
            if (s[i] == '0') 
                r[0]++;
            else 
                r[1]++;
        }
        
        int ans = -1;
        int res = 1e18;
        
        if ((n%2)+(n/2)<r[1] or (n%2)+(n/2)==r[1]){
            res = n;
            ans = 0;
        }
        
        for (int i=0;i<n;i++){
            if (s[i]!='0'){
                r[1]--;
                l[1]++;
            } 
            else{
                r[0]--;
                l[0]++;
            }
            
            int lcount =l[0]+l[1],rcount =r[0]+r[1];
            
            if ((lcount%2) + (lcount/2)<=l[0] and (rcount%2) + (rcount/2) <= r[1]) {
                if (abs(rcount-lcount) < res) {
                    res = abs(rcount-lcount);
                    ans = i + 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
