class Solution {
public:
    int maxFruit(vector<vector<int>>& fruits){
        int n=fruits.size();
        if(n==2){
            return fruits [0][n-1];
        }
        if(n==3){
            return fruits [0][n-1] + fruits [1][n-1];
        }
        vector<vector<int>> dp;
        dp=fruits;
        for(int i=n-2; i>1; i--){
            for(int j=i+1; j<n; j++){
                int x=i-1;
                for(int y=j-1; y<=j+1; y++){
                    if(y>x && y<n && x>=0 && y>=0 && x<n){
                        dp[x][y]=max(dp[x][y], fruits[x][y]+dp[i][j]);
                    }
                }
            }
        }
        return fruits[0][n-1]+ max(dp[1][n-1], dp[1][n-2]);
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size(), ans=0;

         for(int i=0; i<n; i++){
            ans +=fruits[i][i];
         }
         ans+=maxFruit(fruits);
         for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(fruits[i][j], fruits[j][i]);
            }
         }
         ans+=maxFruit(fruits);
         return ans;
    }
};