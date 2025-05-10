class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> onesRow ,onesCol(grid[0].size(), 0) ,zerosRow ,zerosCol(grid[0].size(), 0);
        vector<vector<int>> diff;
        for(int i=0; i<grid.size(); i++){
            int z=0, o=0;
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==0){
                    z++;
                    zerosCol[j]++;
                }
                else{
                    o++;
                    onesCol[j]++;
                }
            }
            onesRow.push_back(o);
            zerosRow.push_back(z);
        }
        for(int i=0; i<grid.size(); i++){
            vector<int> v;
            for(int j=0; j<grid[0].size(); j++){
                v.push_back(onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j]);
            }
            diff.push_back(v);
        }
        return diff;
    }
};