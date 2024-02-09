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

int solve(int start, int end, int year, vector<int>& wines, vector<vector<int>>& dp, vector<vector<char>>& choice){
    if (start > end) return 0;

    if (dp[start][end] != -1) return dp[start][end];

    int pickLeft = wines[start] * year + solve(start + 1, end, year + 1, wines, dp, choice);

    int pickRight = wines[end] * year + solve(start, end - 1, year + 1, wines, dp, choice);

    if (pickLeft >= pickRight) {
        dp[start][end] = pickLeft;
        choice[start][end] = 'L';  
    } else {
        dp[start][end] = pickRight;
        choice[start][end] = 'R';  
    }

    return dp[start][end];
}

void printChoice(vector<vector<char>>& choice, int start, int end) {
    if (start > end) return;

    if (choice[start][end] == 'L') {
        cout << "position " << start + 1 << endl;
        printChoice(choice, start + 1, end);
    } else {
        cout << "position " << end + 1 << endl;
        printChoice(choice, start, end - 1);
    }
}



int32_t main(){
    ab_d();
    int n;
    cin >> n;
    vector<int> wines(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> wines[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<char>> choice(n, vector<char>(n, ' '));
    cout<<solve(0, n - 1, 1, wines, dp, choice)<<endl;

    printChoice(choice, 0, n - 1);
    return 0;
}
