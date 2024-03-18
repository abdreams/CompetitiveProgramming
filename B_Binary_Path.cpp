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

        string row1, row2;
        cin >> row1 >> row2;

        string result;
        int downCount = 0, rightCount = 0;

        for (int i = 0; i < 2 * n; ++i) {
            if (i % 2 == 0) {
                // For even indices, move down
                if (row2[downCount] == '1') {
                    result += '1';
                } else {
                    result += '0';
                }
                downCount++;
            } else {
                // For odd indices, move right
                if (row1[rightCount] == '1') {
                    result += '1';
                } else {
                    result += '0';
                }
                rightCount++;
            }
        }

        cout << result << endl;

        // Counting the number of paths
        long long paths = 1;
        for (char c : result) {
            if (c == '0') {
                paths *= min(downCount, rightCount);
            }
            if (c == '1') {
                if (downCount > 0) {
                    paths *= downCount;
                    downCount--;
                } else {
                    paths *= rightCount;
                    rightCount--;
                }
            }
        }

        cout << paths << endl;
    }
    return 0;
}
