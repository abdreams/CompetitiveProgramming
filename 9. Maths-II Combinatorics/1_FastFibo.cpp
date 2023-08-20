// https://codeforces.com/blog/entry/14516

// f(2 * k) = f(k) * f(k) + f(k - 1) * f(k - 1)
// f(2 * k + 1) = f(k) * f(k + 1) + f(k - 1) * f(k)

// nth fibonacci number

#include <map>
#include <iostream>
using namespace std;

#define long long long
const long M = 1000000007; // modulo
map<long, long> F;

long f(long n) {
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	long n;
	F[0]=F[1]=1;
	while (cin >> n)
	cout << (n==0 ? 0 : f(n-1)) << endl;
    // while (cout>>n){
    //     cout<<(n==0 ? 0 : f(n-1))<<endl;
    //     else if(n=0;n<F.count(n);n++)
    // }
}

