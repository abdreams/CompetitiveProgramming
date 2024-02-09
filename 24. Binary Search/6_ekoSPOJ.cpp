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

bool isPossible(int height, const vector<int>& trees, int M) {
    long long woodCollected = 0;
    
    for (int treeHeight : trees) {
        if (treeHeight > height) {
            woodCollected += (treeHeight - height);
        }
    }

    return woodCollected >= M;
}

int32_t main(){
ab_d();
    int N, M;
    cin >> N >> M;

    vector<int> trees(N);
    for (int i = 0; i < N; ++i) {
        cin >> trees[i];
    }

    sort(trees.begin(), trees.end(), greater<int>());

    int low = 0, high = trees[0], result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(mid, trees, M)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;

    return 0;

}


