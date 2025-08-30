class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            bool row[10] = {false};
            bool col[10] = {false};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row[board[i][j] - '0'])
                        return false;
                    row[board[i][j] - '0'] = true;
                }
                if (board[j][i] != '.') {
                    if (col[board[j][i] - '0'])
                        return false;
                    col[board[j][i] - '0'] = true;
                }
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                bool num[10] = {false};
                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {
                        if (board[r][c] == '.')
                            continue;
                        if (num[board[r][c] - '0'])
                            return false;
                        num[board[r][c] - '0'] = true;
                    }
                }
            }
        }
        return true;
    }
};