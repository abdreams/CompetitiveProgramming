/*
Problem Name: Unique Numbers - II
Problem Difficulty: None
Problem Constraints: n < 10^5
Problem Description:
We are given an array containg n numbers. All the numbers are present twice except for 
two numbers which are present only once. 
Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

Input Format: First line contains the number n. Second line contains n space separated number.
Sample Input: 4
3 1 2 1
Output Format: Output a single line containing the unique numbers separated by space
Sample Output: 2 3
*/

#include<bits/stdc++.h>

using namespace std;

int setbit(int ans){
    int index=0;
    while(ans>0){
        if((ans&1)==1){
            break;
        }
        index++;
        ans=ans>>1;
    } 
    return index;
}

int getBit(int n,int i){

    int mask=1<<i;
    int ans=n&mask;

    if(ans>0) return 1;
    else return 0;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n; //no of elements in array
    vector<int>arr;

    int xor_result=0;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        xor_result=xor_result^x;
        arr.push_back(x);
    }

    cout<< setbit(xor_result)<<endl;


    int bit_Set=setbit(xor_result);
    
    int first_num=0;

    for(int i=0;i<n;i++){
        if(getBit(arr[i],bit_Set)==1){
            first_num=first_num^arr[i];
        }
    }

    cout<<"first num is "<<first_num<<endl;
    cout<<"second num is "<<(first_num^xor_result)<<endl;

    return 0;
}
