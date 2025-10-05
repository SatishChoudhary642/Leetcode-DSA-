class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] |= 1;
            dp[i][m - 1] |= 2;
        }
        for (int i = 0; i < m; i++) {
            dp[0][i] |= 1;
            dp[n - 1][i] |= 2;
        }
        bool change = true;
        while (change) {
            change=false;
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (heights[i][j] >= heights[i - 1][j]) {
                        if(dp[i][j] != (dp[i][j] | dp[i - 1][j])){
                            change=true;
                        }
                        dp[i][j] |= dp[i - 1][j];
                    }
                    if (heights[i][j] >= heights[i][j - 1]) {
                        if(dp[i][j] != (dp[i][j] | dp[i][j-1])){
                            change=true;
                        }
                        dp[i][j] |= dp[i][j - 1];
                    }
                }
            }
            for (int j = m - 2; j >= 0; j--) {
                for (int i = 1; i < n; i++) {
                    if (heights[i][j] >= heights[i - 1][j]) {
                        if(dp[i][j] != (dp[i][j] | dp[i - 1][j])){
                            change=true;
                        }
                        dp[i][j] |= dp[i - 1][j];
                    }
                    if (heights[i][j] >= heights[i][j + 1]) {
                        if(dp[i][j] != (dp[i][j] | dp[i][j+1])){
                            change=true;
                        }
                        dp[i][j] |= dp[i][j + 1];
                    }
                }
            }
            for (int i = n - 2; i >= 0; i--) {
                for (int j = m - 2; j >= 0; j--) {
                    if (heights[i][j] >= heights[i + 1][j]) {
                        if(dp[i][j] != (dp[i][j] | dp[i + 1][j])){
                            change=true;
                        }
                        dp[i][j] |= dp[i + 1][j];
                    }
                    if (heights[i][j] >= heights[i][j + 1]) {
                        if(dp[i][j] != (dp[i][j] | dp[i][j+1])){
                            change=true;
                        }
                        dp[i][j] |= dp[i][j + 1];
                    }
                }
            }
            for (int j = 1; j < m; j++) {
                for (int i = n - 2; i >= 0; i--) {
                    if (heights[i][j] >= heights[i + 1][j]) {
                        if(dp[i][j] != (dp[i][j] | dp[i + 1][j])){
                            change=true;
                        }
                        dp[i][j] |= dp[i + 1][j];
                    }
                    if (heights[i][j] >= heights[i][j - 1]) {
                        if(dp[i][j] != (dp[i][j] | dp[i][j-1])){
                            change=true;
                        }
                        dp[i][j] |= dp[i][j - 1];
                    }
                }
            }
        }
        vector<vector<int>> ans;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (dp[i][j] == 3) {
                        ans.push_back({i, j});
                    }
                }
            }
        return ans;
    }
};