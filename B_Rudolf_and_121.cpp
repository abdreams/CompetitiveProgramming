#include <iostream>
#include <vector>

using namespace std;

bool canMakeZero(vector<int>& a) {
    int n = a.size();

    if (a[0] == 0 && a[n - 1] == 0) {
        return true;
    }
    for (auto &&it : a)
    {
        if (/* condition */)
        {
            /* code */
        }
        else if (/* condition */)
        {
            /* code */
        }
        else
        {
            /* code */
        }
        
        
    }
    
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] > a[i - 1] + a[i + 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (canMakeZero(a)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
