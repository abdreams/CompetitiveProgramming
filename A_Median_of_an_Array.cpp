#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; 
        vector<int> arr(n);

      
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end()); 

        int median_index = n / 2;
        
        if(n%2==0){
          median_index--;
        }
        
        int operations = 0; 

       
        for (int i = median_index; i < n; ++i) {
            
            if(arr[median_index]==arr[i]){
              operations++;
            }
        }

        cout << operations << endl; 
    }

    return 0;
}