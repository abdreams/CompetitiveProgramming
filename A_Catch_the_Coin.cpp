#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size(), result = m;
    for (int start = 0; start < m; start++)
    {
        int curr = start, i2 = start;
        for (int i1 = 0; i1 < n; i1++)
        {
            if (s1[i1] == s2[i2])
            {
                i2++;
                if (i2 == m)
                    break;
            }
        }
        result = min(result, curr + m - i2);
    }
    cout << result + n << '\n';
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}