class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> row(10), col(10);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[board[i][j] - '0']++;
                    if (row[board[i][j] - '0'] >= 2)
                        return false;
                }
                if (board[j][i] != '.') {
                    col[board[j][i] - '0']++;
                    if (col[board[j][i] - '0'] >= 2)
                        return false;
                }
            }
        }
        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                vector<int> num(10);
                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {
                        if (board[r][c] != '.') {
                            num[board[r][c] - '0']++;
                            if (num[board[r][c] - '0'] >= 2)
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};