#include <bits/stdc++.h>

using namespace std;

void oddOrNot(int n){
    // for any number to be odd it's last bit should be 1 eg: 3 is 011, 5 is 101 etc
    // so we take bitwise and with 1 and if it results to 1 then it is odd
    // eg 5&1 = (101 & 001) will evaluate to 1 hence odd
    if(n&1==1) cout<<"N is odd!"<<endl;
    else cout<<"N is even!"<<endl;
}

int getBit(int n,int i){
    // we first make a mask which is 1 at 'i'th index
    // we want to get 'i'(0 indexed)th bit of number n
    // so we and it with the number
    // eg for 5,2 
    // 101 & 100 which results in ans greater than 0 hence bit is 1
    // eg for 5,1
    // 101 & 010 which results in 0 hence we get the bit
    int mask=1<<i;
    int ans=n&mask;

    if(ans>0) return 1;
    else return 0;
}

int setBit(int n,int i){
    // for setting we need to set a bit to 1 so we basically or it with that index
    // eg for 5,1
    // 101 | 010 gives 111 which is 7
    int mask=1<<i;
    return n|mask;
}

int clearBit(int n,int i){
    // clearing a bit means to reset that bit to 0 chahe wo 1 ho ya 0
    // so if we want to clear 2nd bit of 5 (101), we need to and it with 011
    // now to obtain 011 we can negate 100
    // and now we do 101 & 011 which gives us 001 which is 1 
    // and we were successful in clearing the 2nd bit of 5 which was 1
    int mask=~(1<<i);
    return n&mask;
}

int updateBit(int n,int i,int v){
    // clear kardo pehle 
    // uske baad hame i'th bit update krni hai 0 ya 1 se jo ki hai v
    // toh ham v ko left shift maardenge i times
    // aur uske bad uska or lelenge taaki jo bhi value jaisi bhi updatr krni hai wo wahi ho
    // kyuunki already cleared hogi i'th bit toh ek tareeke se ham usse update/ set karrhe hai

    int mask=~(v<<i);
    int cleared_num=n&mask;
    return cleared_num | (v<<i);
}

int clearLastBits(int n,int i){
    int mask= -1<<i;
    return n&mask;
}

int clearRangeItoJ(int n,int i,int j){
    //j>i assumed
    int a=-1<<(j+1);
    int b=(1<<i)-1;
    int mask= a|b;
    return n&mask;

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n,i,v,j;
    cin>>n>>i>>v>>j;

    oddOrNot(n);
    cout<< getBit(n,i)<<endl;
    cout<< setBit(n,i)<<endl;
    cout<< clearBit(n,i)<<endl;
    cout<< updateBit(n,i,v)<<endl;
    cout<< clearLastBits(n,i)<<endl;
    cout<< clearRangeItoJ(n,i,j)<<endl;

    return 0;
}
