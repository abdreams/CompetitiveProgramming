/*
numbers are repeating in sets of 3 and only one number is once
eg [3 3 3 1 1 1 2]
*/

#include<bits/stdc++.h>

using namespace std;

int findUniq(int arr[], int n) {
	int cnt[64] = {0};
	for(int i=0;i<n;i++) {
		int j=0;
		int num=arr[i];
		while(num>0) {
			cnt[j]+= num&1;
			j++;
			num >>= 1;
		}
	}
	int p=1;
	long ans=0;
	for(int i=0;i<64;i++) {
		cnt[i] %= 3;
		ans+=cnt[i]*p;
		p=p<<1;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<findUniq(arr, n);
	return 0;
}
