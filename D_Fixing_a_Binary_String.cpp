#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define int long long

mt19937 rnd(time(0)); 

const int mod = 998244353;

const int MAXN = 2e6 + 7;

void mthrandon

bool isprime[MAXN];
vector<int> prime;
void euler(ll n)
{
    for (ll i = 2; i < n; ++i)
    {
        if (!isprime[i])
            prime.push_back(i);
        for (ll j = 0; j <= (int)prime.size() and i * prime[j] <= n; ++j)
        {
            isprime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    isprime[1] = 1;

}






signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    euler(2e5);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int z0 = 0, z1 = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            if (s[i] == '0')
            {
                z0++;
            }
            else
            {
                z1++;
            }
        }
        int u = rnd() % 1000, v = rnd() % 1000;
        u = prime[u], v = prime[v];
        vector<int> dp1(n + 1);
        vector<int> dp2(n + 1);
        dp1[0] = dp2[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp1[i] = (dp1[i - 1] * u) % mod;
            dp2[i] = (dp2[i - 1] * v) % mod;
        }
        vector<int> hash1(n + 1, 0);
        vector<int> hash2(n + 1, 0);
        vector<int> hash3(n + 1, 0);
        vector<int> hash4(n + 1, 0);
        vector<int> dbug(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            hash1[i] = (hash1[i + 1] * u + s[i] - '0') % mod;
            hash2[i] = (hash2[i + 1] * v + s[i] - '0') % mod;
        }
        for (int i = 1; i <= n; i++)
        {
            hash3[i] = (hash3[i - 1] * u + s[i - 1] - '0') % mod;
            hash4[i] = (hash4[i - 1] * v + s[i - 1] - '0') % mod;
        }
        int zhi1 = 0, zhi2 = 0;
        int zhi3 = 0, zhi4 = 0;
        
        for (int i = 0; i <= n - 1; i++)
        {
            if ((i / k) % 2 == 0)
            {
                zhi1 = (zhi1) % mod;
                zhi2 = (zhi2) % mod;
                zhi3 = (zhi3 + dp1[i]) % mod;
                zhi4 = (zhi4 + dp2[i]) % mod;
            }
            else
            {
                zhi1 = (zhi1 + dp1[i]) % mod;
                zhi2 = (zhi2 + dp2[i]) % mod;
                zhi3 = (zhi3) % mod;
                zhi4 = (zhi4) % mod;
            }
        }

        // auto solve:[&]func(
            vector<int>zhiAgr(n,0);
            bool zhiScn=false;
            for (int j = n - 1; j >= 0; j--)
            {
                for (size_t i = 0; i < n; i++)
                {
                        if(zhi1==zhiAgr[])
                }
                

            }
            
        // )
        
        
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int res1 = 0, res2 = 0;
            res1 = hash1[i];
            res2 = hash2[i];
            res1 = (res1 + hash3[i] * dp1[n - i] % mod) % mod;
            res2 = (res2 + hash4[i] * dp2[n - i] % mod) % mod;
            dbug[i] = res1 + res2;
            if (res1 == zhi1 and res2 == zhi2)
            {
                ans = i;
                break;
            }
            if (res1 == zhi3 and res2 == zhi4)
            {
                ans = i;
                break;
            }
        }
        if (ans == 0)
        {
            cout << -1 << endl;
        }
        else
            cout << ans << endl;
    }
    return 0;
}
