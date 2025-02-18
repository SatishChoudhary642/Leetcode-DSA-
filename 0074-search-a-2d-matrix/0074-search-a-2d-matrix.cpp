class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int beg=0, end=matrix.size()-1, row=0;
        int mid=(beg + end)/2;

        while(beg<=end){
            if(matrix.at(mid).at(0)==target){
                return true;
            }
            else if(matrix.at(mid).at(0)>target){
                end=mid-1;
            }
            else if(matrix.at(mid).at(0)<target){
                beg=mid+1;
                row=mid;
            }
            
            mid=(beg + end)/2;
        }
        beg=0;end=matrix[row].size() -1;
        mid=(beg + end)/2;
        while(beg<=end){
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
        return false;
    }
};