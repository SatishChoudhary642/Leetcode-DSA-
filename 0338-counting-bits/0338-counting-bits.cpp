class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans(n+1,0);
        int cnt=0;
        if(n==0){
            return {0};
        }
        if(n==1){
            return {0,1};
        }
        ans[0]=0;
        ans[1]=1;
        for(int i=2; i<=n ; i++){
            if(i%2==0){
                ans[i]=ans[i/2];
            }
            else{
                ans[i]=ans[i-1]+1;
            }
        }
        return ans;
    }
};