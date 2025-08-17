class Solution {
public:
    
    double new21Game(int n, int k, int maxPts) {
        if(k==0){
            return 1;
        }
        vector<double> dp(n+1);
        dp[0]=1;
        double sum=1;
        for(int i=1; i<=n; i++){
            dp[i]=sum /maxPts;
           if(i<k){
            sum+=dp[i];
           }
           if(i>=maxPts && i-maxPts<k){
            sum-=dp[i-maxPts];
           }
        }
        
        double ans=0;
        for(int i=k; i<=n; i++){
            ans+=dp[i];
        }
        return ans;
    }
};