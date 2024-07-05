#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec_A(n), vec_B(n);
        
        for (auto &val : vec_A) cin >> val;
        for (auto &val : vec_B) cin >> val;

        int cnt = 0, acha = 0, ganda = 0;
        
        for (int i = 0; i < n; i++) {
            if (vec_A[i] == vec_B[i]) {
                if (vec_A[i] == -1) {
                    ganda--;
                } else if (vec_A[i] == 1) {
                    acha++;
                }
            }
        }

        

        int acchaa = 0, burraa = 0;
        
        for (int i = 0; i < n; i++) {
            if (vec_A[i] == vec_B[i]) continue;
            if (vec_A[i] > vec_B[i]) {
                acchaa += vec_A[i];
            } else {
                burraa += vec_B[i];
            
            }
        }

        if (acchaa > burraa) swap(acchaa, burraa);

        cnt = acha;
        int x = min(burraa - acchaa, cnt);
        acchaa += x;
        cnt -= x;
        x = cnt / 2;
        cnt = cnt - x;
        acchaa += max(x, cnt);
        burraa += min(x, cnt);

        if (acchaa > burraa) swap(acchaa, burraa);

        cnt = ganda;
        x = max(acchaa - burraa, cnt);
        burraa += x;
        cnt -= x;
        x = cnt / 2;
        cnt = cnt - x;
        acchaa += max(x, cnt);
        burraa += min(x, cnt);

        cout << min(acchaa, burraa) << endl;
    }
    return 0;
}
