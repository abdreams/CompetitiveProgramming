/*
SPP - Recursive Sequence (Version II)
no tags 
Sequence (ai) of natural numbers is defined as follows:

ai = bi (for i <= k)
ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute am + am+1 + am+2 + ... + an for given m <= n and output it modulo a given positive integer p.

Input
On the first row there is the number C of test cases (equal to about 50).
Each test contains four lines:
k - number of elements of (c) and (b) (1 <= k <= 15)
b1, ... bk - k natural numbers where 0 <= bj <= 109 separated by spaces.
c1, ... ck - k natural numbers where 0 <= cj <= 109 separated by spaces.
m, n, p - natural numbers separated by spaces (1 <= m <= n <= 1018, 1<= p <= 108).
Output
Exactly C lines, one for each test case: (am + am+1 + am+2 + ... + an) modulo p.

Example
Input:
1
2
1 1
1 1
2 10 1000003

Output:
142
*/




#include <bits/stdc++.h>
#define int long long
using namespace std;
int p;


vector<vector<int>> matMult(vector<vector<int>> &A, vector<vector<int>> &B, int size){
    int i, j, k;
    vector<vector<int>> C(size, vector<int>(size));
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            for(k = 0; k < size; k++){
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % p) % p;
            }
        }
    }
    return C;
}

vector<vector<int>> matPow(vector<vector<int>> &t, int n, int size){
    if(n == 1) return t;
    if(n % 2 == 1){
        vector<vector<int>> x = matPow(t, n - 1, size);
        return matMult(t, x, size);
    }
    vector<vector<int>> x = matPow(t, n / 2, size);
    return matMult(x, x, size);
}

int recCompute(int k, vector<int> &b, vector<int> &c, int n){
    if(n < k){
        return b[n];
    }
    vector<vector<int>> T(k + 1, vector<int>(k + 1));
    int i, j;
    for(i = 0; i <= k; i++){
        for(j = 0; j <= k; j++){
            if(i != k && i != 0){
                if(i + 1 == j) T[i][j] = 1;
                else T[i][j] = 0;
            }else{
                if(i == 0 && j == 0){
                    T[i][j] = 1;
                }else if(i == k && j == 0){
                    T[i][j] = 0;
                }else{
                    T[i][j] = c[k - j];
                }
            }
        }
    }
    vector<vector<int>> M = matPow(T, n - k, k + 1);
    int ans = 0;
    for(i = 0; i <= k; i++){
        if(i == 0){
            ans = (ans + M[0][i] * accumulate(b.begin(), b.end(), 0) % p) % p;
        }else{
            ans = (ans + M[0][i] * b[i - 1] % p) % p;
        }
    }
    return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        vector<int> b(k);
        vector<int> c(k);
        int i;
        for(i = 0; i < k; i++) cin >> b[i];
        for(i = 0; i < k; i++) cin >> c[i];
        int m, n;
        int ans = 0;
        cin >> m >> n >> p;
        int t1;
        if(m <= k){
            t1 = accumulate(b.begin(), b.begin() + m - 1, 0); 
        }else{
            t1 = recCompute(k, b, c, m - 1);
        }
        int t2;
        if(n <= k){
            t2 = accumulate(b.begin(), b.begin() + n, 0); 
        }else{
            t2 = recCompute(k, b, c, n);
        }
        ans = ((t2 - t1) % p + p) % p;
        cout << ans << endl;
    }
    return 0;
}

