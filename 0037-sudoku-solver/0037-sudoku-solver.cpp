class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for(int i=0; i<9; i++){
            if(board[r][i]==ch) return false;
            if(board[i][c]==ch) return false;
        }
        int si=(r/3)*3;
        int sj=(c/3)*3;
        for(int i=si; i<si+3; i++){
            for(int j=sj; j<sj+3; j++){
                if(board[i][j]==ch) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char v = '1'; v <= '9'; v++) {
                        if (isValid(board,i,j,v)) {
                            board[i][j] = v;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};