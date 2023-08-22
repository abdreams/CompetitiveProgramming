/*Problem Name: MARBLES
https://www.codechef.com/problems/CODEBU13

Problem Difficulty: 2
Problem Constraints: 1<=T<=100 <br>
1<=k<=n<=1000000
Problem Description:
Hänschen dreams he is in a shop with an infinite amount of marbles. He is allowed to select n marbles. There are marbles of k different colors. From each color, there are also infinitely many marbles. Hänschen wants to have at least one marble of each color, but still there are a lot of possibilities for his selection. In his effort to make a decision he wakes up. Now he asks you how many possibilities for his selection he would have had. Assume that marbles of equal color can't be distinguished, and the order of the marbles is irrelevant.


Input Format: The first line of input contains a number 'T' that indicates the number of test cases to follow. Each test case consists of one line containing n and k, where n is the number of marbles Hänschen selects and k is the number of different colors of the marbles.
Sample Input: 2
10 10
30 7
Output Format: For each test case print the number of possibilities that Hänschen would have had. You can assume that this number exceeds the limit of a signed 64-bit integer.
Sample Output: 1
475020
*/
//https://www.quora.com/Why-does-the-number-of-ways-of-choosing-r-objects-out-of-n-objects-equal-n+r-1-C-r-if-the-selection-is-with-replacement-and-without-arrangement


#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll c(ll n,ll r){   //function to compute nCr
 ll res=1;
 if(r>n/2){
 r=n-r;
 }
 
 for(int i=0;i<r;i++){
 res*=n;
 res/=i+1;
 n--;
 }
 return res;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

 int t; //test cases
 cin>>t;
 while(t--){
 int n,k;
 cin>>n>>k;
 if(k == 1) {
            cout << 1 << endl;
            continue;
        }
 cout<<c(n-1,n-k)<<endl;
 }
 return 0;
}
/*

The key to this is that we only care about the number of times an object has been selected, so it is possible to imagine modeling a choice by placing r stars into n bins. For example say you have to pick 3 ice cream scoops from 8 total to go on your cone. Of course you are allowed to have repeat flavours and we don't really care what order they are in on the cone. We imagine creating the 8 flavour categories by separating them with 7 bars |. This looks like

… | … | … | … | … | … | … | …

these are our  𝑛=8
  bins representing the 8 flavours (the dots are just to separate the bars so you can see them clearly) but notice we are only using  𝑛−1=7
  bars.

Next we can model a choice with replacement (I.e. with repetition allowed) by filling some of these bins with  𝑟=3
  stars, so we might have

☆☆☆| … | … | … | … | … | … | … (3 scoops of flavour 1)

or

…| ☆ | … | ☆ | … | ☆ | … | … (1 scoop each of flavours 2, 4 and 6)

If we remove the dots these selections look like

☆☆☆| | | | | | | and | ☆ | | ☆ | | ☆ | | which look suspiciously like two possible arrangements of 3 stars and 7 bars.

In fact it should now be obvious that every choice with replacement of 3 scoops from 8 flavours is uniquely represented by an arrangement of the 7 bars and 3 stars and that there are no choices that are not represented (this is called a bijection). Hence we can count these arrangements using basic combinatorics to give  (7+33)
  choices with replacement for this example.

In general there will be  𝑟
  stars and  𝑛−1
  bars hence

choices of r objects from n with replacement=(𝑛−1+𝑟 c 𝑟)
*/