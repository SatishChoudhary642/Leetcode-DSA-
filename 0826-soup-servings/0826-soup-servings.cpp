class Solution {
public:
    double pro(int A, int B, vector<vector<double>>& dp) {
        if (A>0 &&  B>0 && dp[A][B] != -1) {
            return dp[A][B];
        }
        if (A <= 0 && B <= 0) {
            return 0.5;
        } else if (A <= 0) {
            return 1;
        } else if (B<=0){
            return 0;
        }
        
        dp[A][B] = 0.25 * (pro(A - 100, B, dp) + pro(A - 75, B - 25, dp) +
                           pro(A - 50, B - 50, dp) + pro(A - 25, B - 75, dp));
        return dp[A][B];
    }
    double soupServings(int n) {
        if(n>5000){
            return 1;
        }
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
        return pro(n, n, dp);
    }
};