#include <bits/stdc++.h>
#define int long long

using namespace std;

int n = 10000000;
bitset<10000005> b; // stores a bit indicating 1 or 0 at each index
vector<int> primes;

int calculate_gcd(int a, int bno) {
    if (bno == 0) return a;
    return calculate_gcd(bno, a % bno);
}

void sieve() {
    for (int i = 3; i <= n; i = i + 2) {
        b[i] = 1;
    }

    for (int i = 3; i <= n; i = i + 2) {
        if (b[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                b[j] = 0;
            }
        }
    }
    b[2] = 1;
    b[1] = b[0] = 0;

    for (int i = 0; i <= n; i++) {
        if (b[i] == 1) primes.push_back(i);
    }
}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    sieve(); // Call the sieve function to calculate primes

    while (t--) {
        int a, y;
        cin >> a >> y;

        int flag=0;

       for(int i=1;i<y;i++){
            if(b[i]==0){
                int j=y-i;
                if(i+j<a) continue;
                int x=calculate_gcd(i,j);
                if(x!=1){
                    cout<<i<<" "<<j<<endl;
                    flag=1;
                    break;
                }
            }
       }
        if(flag==0) cout<<-1<<endl;

    }

    return 0;
}
