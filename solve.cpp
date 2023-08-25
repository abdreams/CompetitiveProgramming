#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;
	cin>>t;
	while (t--)
	{
		int n,m;
		cin>>n>>m;
		vector<vector<char>>strings(n+1,vector<char>(m+1));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>strings[i][j];
			}
		}
		int vpos=-1;
		int ipos=-1;
		int kpos=-1;
		int apos=-1;
		string temp;

		int j;
		for(j=0;j<m;j++){
			for(int i=0;i<n;i++){
				if(strings[i][j]=='v'){
					temp+='v';
					j++;
					break;
					cout<<j<<endl;
				}
			}
		}
		for(j;j<m;j++){
			for(int i=0;i<n;i++){
				if(strings[i][j]=='i'){
					temp+='i';
					j++;
					break;
				}
			}
		}
		for(j;j<m;j++){
			for(int i=0;i<n;i++){
				if(strings[i][j]=='k'){
					temp+='k';
					j++;
					break;
				}
			}
		}
		
		for(j;j<m;j++){
			for(int i=0;i<n;i++){
				if(strings[i][j]=='a'){
					temp+='a';
					j++;
					break;
				}
			}
		}

	

		cout<<temp<<endl;
		
		
	}
	

	return 0;
}
