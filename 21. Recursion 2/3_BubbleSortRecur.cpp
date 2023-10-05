#include<bits/stdc++.h>

using namespace std;

void bubble_sort(int arr[], int n) {
    if (n == 1) return;

    int didSwap = 0;
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j],arr[j+1]);
            didSwap = 1;
        }
    }
    if (didSwap == 0) return;
    bubble_sort(arr, n - 1);
}

void bubble_sort_recursive(int arr[],int n,int j){
    if(n==1) return;
    if(j==n-1) return bubble_sort_recursive(arr,n-1,0);

    if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);

    return bubble_sort_recursive(arr,n,j+1);
    
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int arr[] = {13, 46, 24, 52, 20, 9};
    int n=6;
    bubble_sort_recursive(arr,n,0);
    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}
