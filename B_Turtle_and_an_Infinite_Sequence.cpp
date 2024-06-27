#include <bits/stdc++.h>
using namespace std;
#define int long long

int orr(int l, int m)
{
    int ans;
    ans = 0;
    for (int i = 0; i <= 40; i++)
    {
        if (l & (1ll << i))
        {
            ans += (1ll << i);
        }
        else
        {
            int zz;
            zz = l & ((1ll << (i + 1)) - 1);
            zz = (1ll << i) - zz;
            if (zz <= m)
            {
                ans += (1ll << i);
            }
        }
    }
    return ans;
}
void _main()
{
    int n, m;
    cin >> n >> m;
    int ans;
    ans = orr(n, m);
    if (n - m >= 0)
    {
        ans |= orr(n - m, m);
    }
    else
    {
        ans |= orr(0, n);
    }
    cout << ans << endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        _main();
    }
    return 0;
}