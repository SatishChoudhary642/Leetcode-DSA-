class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // queue<bool> q;
        // for(int i=1; i<=n; i++){
        //     while(q.size()>delay){
        //         q.pop();
        //     }
        // }
        long long aware=0, ans=0, mod=1e9+7;
        vector<long long> dp(n);
        dp[0]=1;
        for(int i=1; i<n; i++){
            if(i-delay>=0){
                aware=(aware + dp[i-delay])%mod;
            }
            if(i-forget>=0){
                aware=(aware - dp[i-forget] + mod)%mod;
            }
            dp[i]=aware;
        }
        for(int i=n-forget; i<n; i++){
            ans=(ans + dp[i])%mod;
        }
        return ans;
    }
};