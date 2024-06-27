#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int minTents = 0;

        minTents += a;


        if (b % 3 != 0) {
            int extra = 3 - b % 3;
            if (c >= extra) {
                b += extra;
                c -= extra;
            } else {
                cout << "-1" << endl;
                continue; 
            }
        }
        b /= 3;

        if (c % 2 == 0) {
            minTents += min(b, c / 2);
        } else {
            cout << "-1" << endl;
            continue; 
        }

        cout << minTents << endl;
    }

    return 0;
}
