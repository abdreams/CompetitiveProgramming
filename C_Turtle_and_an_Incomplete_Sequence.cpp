// LUOGU_RID: 161020256
#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[200009];
int f[200009];
int a[200009];
int lcp(string a,string b){
	for(int i=0;i<min(a.size(),b.size());i++){
		if(a[i]!=b[i]){
			return i;
		}
	}
	return min(a.size(),b.size());
}
void _main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		s[i]="";
		int x;
		cin>>x;
		a[i]=x;
		if(x==-1){
			s[i]="-";
		}else{
			while(x){
				s[i]=char((x&1)+'0')+s[i];
				x>>=1;
			}
		}
		if(s[i-1]!="-"){
			f[i]=i-1;
		}else{
			f[i]=f[i-1];
		}
	}
	int t;
	t=n;
	if(s[t]=="-"){
		t=f[t];
	}
	while(f[t]){
		//cout<<t<<" "<<f[t]<<endl;
		int z;
		z=f[t];
		int c;
		c=lcp(s[z],s[t]);
		//cout<<(t-z)-(int)(s[t].size()-c+s[z].size()-c)<<endl;
		if((t-z)-(int)(s[t].size()-c+s[z].size()-c)>=0&&((t-z)-(int)(s[t].size()-c+s[z].size()-c))%2==0){
			int ii;
			ii=t-1;
			for(int i=t-1;s[t].size()+i-t>=c;i--,ii=i){
				a[i]=a[i+1]/2;
			}
			int jj;
			jj=z+1;
			for(int i=z+1;s[z].size()+z-i>=c;i++,jj=i){
				a[i]=a[i-1]/2;
			}
			for(int i=jj;i<=ii;i++){
				if(i==jj)
				a[i]=a[i-1]*2;
				else
				a[i]=a[i-2];
			}
			t=z;
		}else{
			cout<<-1<<endl;
			return;
		}
	}
	int ss;
	ss=0;
	for(int i=n;i>=1;i--){
		if(a[i]!=-1){
			ss=i;
		}
	}
	for(int i=ss-1;i>=1;i--){
		if(i==ss-1)
		a[i]=a[i+1]*2;
		else
		a[i]=a[i+2];
	}
	ss=n+1;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			ss=i;
		}
	}
	for(int i=ss+1;i<=n;i++){
		if(i==ss+1)
		a[i]=a[i-1]*2;
		else
		a[i]=a[i-2];
	}
	if(a[1]==-1){
		for(int i=1;i<=n;i++){
			a[i]=(1<<(i&1));
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		_main();
	}
	return 0;
}