class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp=matrix;
        int ans=0;
        for(int i=0; i<dp.size(); i++){
            for(int j=0; j<dp[0].size(); j++){
                if(i-1>=0 && j-1>=0 && dp[i][j]!=0){
                    dp[i][j]=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                }
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};