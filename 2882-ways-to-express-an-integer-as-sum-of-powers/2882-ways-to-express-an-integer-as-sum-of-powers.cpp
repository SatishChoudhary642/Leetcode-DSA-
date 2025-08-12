class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> num;
        long long mod=1e9 + 7;
        for(int i=1; pow(i,x)<=n; i++){
            num.push_back(pow(i,x));
        }
        vector<long long> dp(n+1, 0);
        dp[0]=1;
        for(int i=1; i<=num.size(); i++){
            for(int j=n; j>=num[i-1]; j--){
                dp[j]=(dp[j] + dp[j-num[i-1]])%mod;
            }
        }

        return dp[n];
    }
}; 