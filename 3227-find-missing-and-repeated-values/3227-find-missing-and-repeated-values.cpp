class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=n*n;
        vector <int> arr(m);
        vector <int> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[grid[i][j] - 1]++;
            }
        }
        for(int k=0; k<m; k++){
            if(arr[k]==0){
                ans.push_back(k+1);
            }
            else if(arr[k]==2){
                ans.insert(ans.begin(), k+1);
            }
        }
        return ans;
    }
};