/*
Problem Name: Not So Easy Math
Problem Difficulty: None
Problem Constraints: 1 <= test cases <= 10
1 <= n <= 10^18
Problem Description:
After the release of Avengers, _Ironman_ and _Thor_ got into a fight and Ironman challenged Thor to find out the number of numbers between 1 and n which are divisible by any of the prime numbers less than 20.
Ironman being great at maths quickly answered the question but then Thor asked him to write a program for it. Ironman however found it quite difficult as he did not wanted to write so many lines of code. he knows that you are smart and can code this up easily. Can you do it?

Input Format: The first line consists of number of test cases t.
then follow t lines which consists of number n for each test case.
Sample Input: 5
5
10 
12
15
18
Output Format: the answer to each test case each in different line
Sample Output: 4
9
11
14
17
*/

#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ll t;
    cin>>t;
    
    int primes[]={2,3,5,7,11,13,17,19};

    while(t--){
        ll num;
        cin>>num;

        ll subsets=(1<<8)-1;
        ll ans=0;

        for(ll i=1;i<=subsets;i++){
            ll denom=1ll;
            ll setbits=__builtin_popcount(i);
            
            for(int j=0;j<8;j++){
               if(i&(1<<j)) denom=denom*primes[j];
            }
            if(setbits&1){
                ans+=num/denom;
            }
            else{
                ans-=num/denom;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
