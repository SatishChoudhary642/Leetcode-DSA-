class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>> ans (c,vector<int>(r));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
               ans.at(j).at(i)=matrix.at(i).at(j);
            }
        }
        return ans;
    }
};