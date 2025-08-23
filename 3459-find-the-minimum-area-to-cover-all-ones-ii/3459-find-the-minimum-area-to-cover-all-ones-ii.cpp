class Solution {
public:
    int minrec(int l, int r, int t, int b, vector<vector<int>>& grid) {
        int left = r, right = l, top = b, bottom = t;
        bool found = false;
        for (int row = t; row <= b; row++) {
            for (int col = l; col <= r; col++) {
                if (grid[row][col] == 1) {
                    found = true;
                    left = min(left, col);
                    right = max(right, col);
                    top = min(top, row);
                    bottom = max(bottom, row);
                }
            }
        }
        if (!found)
            return INT_MAX;
        return (bottom - top + 1) * (right - left + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int ans = INT_MAX, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < m - 2; i++) {
            for (int j = i + 1; j < m - 1; j++) {
                int r1 = minrec(0, i, 0, n - 1, grid);
                int r2 = minrec(i + 1, j, 0, n - 1, grid);
                int r3 = minrec(j + 1, m - 1, 0, n - 1, grid);
                if (r1 != INT_MAX && r2 != INT_MAX && r3 != INT_MAX)
                    ans = min(ans, r1 + r2 + r3);
            }
        }

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int r1 = minrec(0, m - 1, 0, i, grid);
                int r2 = minrec(0, m - 1, i + 1, j, grid);
                int r3 = minrec(0, m - 1, j + 1, n - 1, grid);
                if (r1 != INT_MAX && r2 != INT_MAX && r3 != INT_MAX)
                    ans = min(ans, r1 + r2 + r3);
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int r1 = minrec(0, m - 1, 0, i, grid);
                int r2 = minrec(0, j, i + 1, n - 1, grid);
                int r3 = minrec(j + 1, m - 1, i + 1, n - 1, grid);
                if (r1 != INT_MAX && r2 != INT_MAX && r3 != INT_MAX)
                    ans = min(ans, r1 + r2 + r3);
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int r1 = minrec(0, m - 1, i + 1, n - 1, grid);
                int r2 = minrec(0, j, 0, i, grid);
                int r3 = minrec(j + 1, m - 1, 0, i, grid);
                if (r1 != INT_MAX && r2 != INT_MAX && r3 != INT_MAX)
                    ans = min(ans, r1 + r2 + r3);
            }
        }

        for (int j = 0; j < m - 1; j++) {
            for (int i = 0; i < n - 1; i++) {
                int r1 = minrec(0, j, 0, n - 1, grid);
                int r2 = minrec(j + 1, m - 1, 0, i, grid);
                int r3 = minrec(j + 1, m - 1, i + 1, n - 1, grid);
                if (r1 != INT_MAX && r2 != INT_MAX && r3 != INT_MAX)
                    ans = min(ans, r1 + r2 + r3);
            }
        }

        for (int j = 0; j < m - 1; j++) {
            for (int i = 0; i < n - 1; i++) {
                int r1 = minrec(j + 1, m - 1, 0, n - 1, grid);
                int r2 = minrec(0, j, 0, i, grid);
                int r3 = minrec(0, j, i + 1, n - 1, grid);
                if (r1 != INT_MAX && r2 != INT_MAX && r3 != INT_MAX)
                    ans = min(ans, r1 + r2 + r3);
            }
        }
        return ans;
    }
};