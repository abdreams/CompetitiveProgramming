// semper fi //
// abdreams //
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define w(x)            int x; cin>>x; while(x--)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}


bool isValidPosition(int row, int col, int N) {
    return row >= 0 && row < N && col >= 0 && col < N;
}


bool isItSafe(vector<vector<bool>>& board, int row, int col) {
    int N = board.size();
    if (isValidPosition(row - 2, col - 1, N) && board[row - 2][col - 1]) {
        return false;
    } else if (isValidPosition(row - 2, col + 1, N) && board[row - 2][col + 1]) {
        return false;
    } else if (isValidPosition(row - 1, col - 2, N) && board[row - 1][col - 2]) {
        return false;
    } else if (isValidPosition(row - 1, col + 2, N) && board[row - 1][col + 2]) {
        return false;
    } else if (isValidPosition(row + 1, col - 2, N) && board[row + 1][col - 2]) {
        return false;
    } else if (isValidPosition(row + 1, col + 2, N) && board[row + 1][col + 2]) {
        return false;
    } else if (isValidPosition(row + 2, col - 1, N) && board[row + 2][col - 1]) {
        return false;
    } else if (isValidPosition(row + 2, col + 1, N) && board[row + 2][col + 1]) {
        return false;
    }

    return true;
}


int countNKnights(vector<vector<bool>>& board, int placed, int sr, int sc) {
    if (placed == board.size()) {
        return 1;
    }

    int count = 0;

    for (int row = sr; row < board.size(); row++) {
        for (int col = (row == sr ? sc : 0); col < board.size(); col++) {
            if (!board[row][col] && isItSafe(board, row, col)) {
                board[row][col] = true;
                count += countNKnights(board, placed + 1, row, col + 1);
                board[row][col] = false;
            }
        }
    }

    return count;
}

void printNKnights(vector<vector<bool>>& board, int placed, int sr, int sc, string osf) {
    if (placed == board.size()) {
        cout << osf << "   ";
        return;
    }

    for (int row = sr; row < board.size(); row++) {
        for (int col = (row == sr ? sc : 0); col < board.size(); col++) {
            if (!board[row][col] && isItSafe(board, row, col)) {
                board[row][col] = true;
                printNKnights(board, placed + 1, row, col + 1, osf + "{" + to_string(row) + "-" + to_string(col) + "} ");
                board[row][col] = false;
            }
        }
    }
}



int32_t main() {
ab_d();
    int N;
    cin >> N;

    vector<vector<bool>> board(N, vector<bool>(N, false));

    cout << countNKnights(board, 0, 0, 0) << endl;
    printNKnights(board, 0, 0, 0, "");

    return 0;
}
