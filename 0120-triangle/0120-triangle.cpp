class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> v = triangle;
        for(int i=1; i<v.size(); i++){
            for(int j=0; j<v[i].size(); j++){
                int a=INT_MAX, b=INT_MAX;
                if(j-1>=0){
                    b=v[i-1][j-1];
                }
                if(j<v[i-1].size()){
                    a=v[i-1][j];
                }
                v[i][j]+=min(a,b);
            }
        }
        int ans=INT_MAX, row=v.size()-1;
        for(int i=0; i<v[row].size(); i++){
            ans=min(ans, v[row][i]);
        }
        return ans;
    }
};