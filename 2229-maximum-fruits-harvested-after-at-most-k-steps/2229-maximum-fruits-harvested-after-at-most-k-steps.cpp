class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans=0, n=fruits.size();
        int mx=max((startPos + k), fruits[n-1][0]);
        vector<int> pre (mx + 2);
        for(int i=0; i<n; i++){
            pre[fruits[i][0]+1]=fruits[i][1];
        }
        for(int i=1; i<=mx+1; i++){
            pre[i]+=pre[i-1];
        }

        for(int x=0; x<=k/2; x++){
            int r1=min(mx,startPos + x);
            int l1=max(0, startPos + x - (k-x));
            ans=max(ans, pre[r1+1] - pre[l1]);

            int l2=max(0,startPos - x);
            int r2=min(mx,startPos - x + (k-x));
            ans=max(ans, pre[r2+1] - pre[l2]);
        }
        return ans;
    }
};