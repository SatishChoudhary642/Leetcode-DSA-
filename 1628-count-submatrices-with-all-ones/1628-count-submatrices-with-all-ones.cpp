class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<int> height(mat[0].size(),0);

        int ans=0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
                int minh=height[j], sum=0;
                for(int k=j; k>=0; k--){
                    minh=min(minh, height[k]);
                    sum+=minh;
                }
                ans+=sum;
            }
        }
        return ans;
    }
};