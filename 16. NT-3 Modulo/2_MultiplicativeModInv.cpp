#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int* x, int* y);

void modInverse(int A, int M)
{
	int x, y;
	int g = gcdExtended(A, M, &x, &y);
	if (g != 1)
		cout << "Inverse doesn't exist";
	else {

		int res = (x % M + M) % M;
		cout << "Modular multiplicative inverse is " << res;
	}
}

int gcdExtended(int a, int b, int* x, int* y)
{

	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}

	int x1, y1;
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	int A = 6, M = 7;

	modInverse(A, M);
	return 0;
}

