#include<bits/stdc++.h>

using namespace std;

 void decodeAtIndex(string s, int k) {

        string tape;
        string curr;

        for(int i=0;i<s.size();i++){
            if((it>='a' and it<='z') or (it>='A' and it<='Z')){
                curr+=it;
                tape+=it;
            }
            else{
                while((it-1)!=0){
                    tape+=curr;
                    it--;
                }
            }
        }

        string ans;
        ans+= tape[k-1];
        cout<< ans<<endl;
		cout<<tape<<endl;
    }

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
// Input: s = "leet2code3", k = 10
// Output: "o"
	string s="leet2code3";
	int k=10;
	decodeAtIndex(s,k);

	return 0;
}
