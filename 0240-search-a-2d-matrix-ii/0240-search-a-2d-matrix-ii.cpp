class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0, col=matrix[0].size()-1;
        while(row<matrix.size() && col<matrix[0].size()){
            if(matrix.at(row).at(col)==target){
                return true;
            }
            else if(matrix.at(row).at(col)<target){
                row++;
            }
            else if(matrix.at(row).at(col)>target){
                col--;
            }
        }
        return false;
    }
};