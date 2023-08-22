/* 
Problem Name: Boston Numbers
Problem Difficulty: None
Problem Constraints: 1 < N < 2,147,483,647 (max value of an integer of the size of 4 bytes)


Problem Description:
A Boston number is a composite number, the sum of whose digits is the sum of the digits of its prime factors obtained as a result of prime factorization (excluding 1 ). The first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 . For example, 378 = 2 × 3 × 3 × 3 × 7 is a Boston number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7. Write a program to check whether a given integer is a Boston number.


Input Format: There will be only one line of input:N , the number which needs to be checked.


Sample Input: 378
Output Format: 1 if the number is a Boston number. 0 if the number is a not Boston number.


Sample Output: 1*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n, sum=0, sum_n=0;  cin>>n;
    int temp=n;
    while(temp>0)
    {
        sum_n=sum_n+(temp%10);
        temp/=10;
    }
    while (n%2 == 0)
    {
        sum+=2;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
           int temp1=i;
            while(temp1>0){
        sum=sum+(temp1%10);
        temp1/=10;
                }

            n = n/i;
        }
    }
    
    if (n > 2)
    {  while(n>0)
    {
        sum=sum+(n%10);
        n/=10;
    }
    }

    if(sum_n==sum)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}