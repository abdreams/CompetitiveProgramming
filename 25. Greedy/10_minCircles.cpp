#include <bits/stdc++.h>
using namespace std;

#define int long long

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int32_t main(){
    ab_d();

    int n;
    cin >> n;

    vector<pair<int, int>> circles(n);
    for (int i = 0; i < n; ++i) {
        cin >> circles[i].first >> circles[i].second;
    }

    sort(circles.begin(), circles.end(), [](const auto &a, const auto &b) {
        return a.first + a.second < b.first + b.second;
    });

    int countNonOverlap = 1;
    int lastEndPoint = circles[0].first + circles[0].second;

    for (int i = 1; i < n; ++i) {
        int currentStartPoint = circles[i].first - circles[i].second;

        if (currentStartPoint >= lastEndPoint) {
            countNonOverlap++;
            lastEndPoint = circles[i].first + circles[i].second;
        }
    }

    cout << n - countNonOverlap << endl;

    return 0;
}
