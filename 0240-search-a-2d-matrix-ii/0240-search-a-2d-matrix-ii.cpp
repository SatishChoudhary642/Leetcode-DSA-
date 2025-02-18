class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int row=0; row<matrix.size(); row++){
            int beg=0, end=matrix[row].size()-1;
            int mid=(beg + end)/2;
            while(beg<=end && target<=matrix.at(row).at(end)){
                if(matrix.at(row).at(mid)==target){
                return true;
            }
            else if(matrix.at(row).at(mid)>target){
                end=mid-1;
            }
            else if(matrix.at(row).at(mid)<target){
                beg=mid+1;
            }
            mid=(beg + end)/2;
            }
        }
        return false;
    }
};