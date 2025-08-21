class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        vector<int> height(matrix[0].size(),0);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
                int h=height[j], sum=0;
                for(int k=j; k>=0; k--){
                    h=min(h, height[k]);
                     ans=max(h*(j-k+1),ans);
                }
            }
        }
        return ans;
    }
};