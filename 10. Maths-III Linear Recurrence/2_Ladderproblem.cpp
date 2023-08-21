// Matrix expontiation O(k^3 log(n))
// ladder problem
// for Linear Recurrences 

/*
if you are stand at n=0(ground) . then how many ways to go over the nth steps.
INPUT :
give T , k ,n ; where T is tescases , k is no. of jumps he  can take, n is nth element

for example 
T = 1;
k = 3 {1,2,3} // he can take 1 or 2 or 3 steps at a time
n =5 // 5th element we have to find
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define MOD 1000000000
ll k;
vector<ll> b;

vector<ll> c;

vector<vector<ll> > mul(vector<vector<ll> > A, vector<vector<ll> > B){
    vector<vector<ll> > C(k+1, vector<ll>(k+1));
    for(int i = 1;i<=k;i++){
        for(int j = 1;j<=k;j++){
            for(int x = 1;x<=k;x++)
                C[i][j] = (C[i][j] + A[i][x]*B[x][j]) % MOD;
        }
    }
return C;
}
vector<vector<ll> > pow(vector<vector<ll> > A, ll p){
    if(p == 1)
    return A;
    if(p & 1)
    return mul(A,pow(A,p-1));
    vector<vector<ll> > X = pow(A,p/2);
    return mul(X,X);
}
ll compute(ll n){
    if(n == 0)
    return 0;

    if(n <= k)
    return b[n-1];

    vector<ll> F1(k+1);
    for(int i = 1;i<k+1;i++)
    F1[i] = b[i-1];

    vector<vector<ll> > T(k+1,vector<ll>(k+1));
    for(int i = 1;i<=k;i++){
        for(int j = 1;j<=k;j++){
            if(i<k){
                if(j == i+1)
                T[i][j] = 1;
                else 
                T[i][j] = 0;
                
            }

           else
            T[i][j] = 1;
        }
    }

    T = pow(T,n-1);
    ll res = 0;
    for(int i = 1;i<=k;i++){
    res = (res + T[1][i]*F1[i]) % MOD;
    }
    return res % MOD;
}
int main(){
    ll t,n,num;
    cin>>t;
    while(t--){
     
        cin>>k;
        num = 1;
        for(int i=0;i<k;i++){
            b.push_back(num);
            num = num * 2;
           
        }
        cin>>n; 

        cout<<compute(n)<<endl;
        b.clear();
        c.clear();

    }
}