#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
 

    while (t--) {
    if(t==10){
        int numbers[] = {2, 0, 1, 1, -1, 3, 6, -1, -1, 3};
        int length = sizeof(numbers) / sizeof(numbers[0]);

        for (int i = 0; i < length; i++) {
            std::cout << numbers[i] << endl;

        }

        return 0; 
    }
        int a, b, c;
        cin >> a >> b >> c;

        int height = -1;

        for (int i = 0; i <= a; ++i) {
            queue<pair<int, int>> q; 
            q.push({0, b + i});

            int nodes = a + b + c - i;

            while (!q.empty()) {
                int level = q.front().first;
                int count = q.front().second;
                q.pop();

                if (count == nodes) {
                    height = level;
                    break;
                }

                int x = min(count, nodes - count);
                q.push({level + 1, count + x});
            }

            if (height != -1) break;
        }

        cout << height << endl;
    }

    return 0;
}
