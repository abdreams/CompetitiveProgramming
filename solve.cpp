// #include<bits/stdc++.h>

// using namespace std;
// vector<string>substrings;

// void generateSubstrings(const string& str) {
//     int n = str.length();

//     for (int mask = 1; mask < (1<<n); ++mask) {
//         string temp="";
//         for (int i = 0; i < n; ++i) {
//             if (mask & (1 << i)) {
//                 temp+= str[i];
//             }
//         }
//         substrings.push_back(temp);
//     }
// }


// int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
//     string s;
//     cin>>s;
//     int n=s.length();
//     generateSubstrings(s);
//     for(int i=0;i<(1<<n);i++){
//         cout<<substrings[i]<<endl;
//     }
//     int sum=0;
//     for(int i=0;i<(1<<n);i++){
//         int num=stoi(substrings[i]);
//         cout<<num<<endl;
//         sum+=num;
//         cout<<i<<"th sum is: "<< sum<<endl;
//     }
//     cout<<"sum is"<<sum<<endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

void findSumOfExpressions(string S, int N)
{

unsigned long long sumOfExp = 0;

for (int i = 0; i < pow(2, N - 1); i++) {

	unsigned long long ans_sub = 0;


	string subst = string(1, S.at(0));
    cout<<subst<<endl;


	for (int j = 0; j < N - 1; j++) {

	if (((i >> j) & 1) == 1) {

		ans_sub += stoull(subst);

		subst = string(1, S.at(j + 1));
        // cout<<subst<<endl;
	}
	else

		subst += S.at(j + 1);

	if (j == N - 2)
		ans_sub += stoull(subst);
	}


	sumOfExp += ans_sub;
}

if (N == 1)
	cout << S;
else


	cout << sumOfExp;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif


string S = "123";


int N = S.length();

findSumOfExpressions(S, N);
}



