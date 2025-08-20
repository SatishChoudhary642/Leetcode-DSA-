class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        vector<vector<int>> dp;
        for(int i=0; i<matrix.size(); i++){
            vector<int> v;
            for(int j=0; j<matrix[0].size(); j++){
                v.push_back(matrix[i][j]-'0');
            }
            dp.push_back(v);
        }
        for(int i=0; i<dp.size(); i++){
            for(int j=0; j<dp[0].size(); j++){
                if(i-1>=0 && j-1>=0 && dp[i][j]!=0){
                    dp[i][j]=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) +1;
                }
                 ans=max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};