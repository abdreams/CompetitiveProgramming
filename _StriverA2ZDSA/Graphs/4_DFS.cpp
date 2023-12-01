class Solution {
public:
    bool issafeNqueen(vector<string> &soln,int col, int row, int n){
        for(int l = 0 ; l < n ; l++){
            if(soln[l][col]=='Q') return false;
        }

        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(soln[i][j] == 'Q'){
                return false;
            }
        }
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(soln[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void solve(vector<vector<string>> &board,int n,int row,vector<string> &soln){
        if(row==n){
            board.push_back(soln);
            return;
        }
        for(int i = 0 ; i < n ; i++){
            if(issafeNqueen(soln,i,row,n)){
                soln[row][i] = 'Q';
                solve(board,n,row+1,soln);
                soln[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board;
        vector<string> soln(n, string(n,'.'));
        solve(board,n,0,soln);
        return board;
    }
};