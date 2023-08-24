//https://hack.codingblocks.com/app/practice/1/137/problem

// https://www.justquant.com/numbertheory/highest-power-of-a-number-in-a-factorial/

/*
Mike found an interesting problem. In this problem you are given two integers, *n* and *k*. You need to find the the maximum value of *x*, such that, n! % k^x = 0.

Input Format: First line contains number of test cases, T. Each test case contains two integers each, *n* and *k*.
Sample Input: 2
5 2
1000 2

Output Format: Print the value of *x* for each test case.
Sample Output: 3
994
*/


#include<bits/stdc++.h>

using namespace std;

map<int,int> mp;
map<int,int> mp_numrange;

void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        mp[2]++;
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n = n/i;
        }
    }
 
    if (n > 2)
        mp[n]++;
}

// int32_t count(int n, int p)
// {   
//     int ratio=0;
//     int i = p;
//     while ((p) <= n)
//     {
//         ratio += (n / p);
//         p = p * i;
//     }
//     return ratio;
// }

void getCount(int l, int r, int p)
{
    int cnt = 0;
    int val = p;
    while (1) {
        int a = r / val;
        int b = (l - 1) / val;
        val *= p;
        if (a - b) {
            cnt += (a - b);
        } else
            break;
    }
    mp_numrange[p]=cnt;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        mp.clear(); 
        mp_numrange.clear(); 
        
        primeFactors(k);

        for(auto it:mp){
            if(it.second!=0){
                getCount(2, n, it.first);
            }
        }
        int mini = INT_MAX;
        

        for(auto it:mp){
            if(it.second!=0){
                int pow_in_numerator = mp_numrange[it.first];           
                mini = min(mini, pow_in_numerator / it.second);
            }
        }

        cout << mini << endl;
        
    } 

    return 0;
}

