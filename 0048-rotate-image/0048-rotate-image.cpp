class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();

        for(int i=0; i<n; i++){
            for(int j=i; j<n ; j++){
                swap(matrix[j][i],matrix[i][j]);
            }
            for(int k=0; k<n/2; k++){
                swap(matrix[i][k],matrix[i][n-k-1]);
            }
        }
    }
};