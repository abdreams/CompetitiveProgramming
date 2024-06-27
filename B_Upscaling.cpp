#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Output the checkerboard pattern
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 2; ++k) {
                    for (int l = 0; l < n; ++l) {
                        if ((i + j) % 2 == 0)
                            cout << "#";
                        else
                            cout << ".";
                    }
                    if (j == n - 1)
                        cout << endl;
                }
            }
        }

        // Output an empty line between test cases
        if (t > 0)
            cout << endl;
    }

    return 0;
}
