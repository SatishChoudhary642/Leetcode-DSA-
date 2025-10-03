
class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> boundary; //minHeap
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            boundary.push({heightMap[i][0], i, 0});
            boundary.push({heightMap[i][n-1], i, n-1});
            vis[i][0] = 1; vis[i][n-1] = 1;
        }
        for(int j=1;j<n-1;j++){
            boundary.push({heightMap[0][j], 0, j});
            boundary.push({heightMap[m-1][j], m-1, j});
            vis[0][j] = 1; vis[m-1][j] = 1;
        }
        int total = 0;
        while(!boundary.empty()){
            auto cur = boundary.top(); boundary.pop();
            int minBH = cur[0], row = cur[1], col = cur[2];
            for(int i=0;i<4;i++){
                int n_row = row + dir[i][0], n_col = col + dir[i][1];
                if(n_row<0 || n_row>=m || n_col<0 || n_col>=n || vis[n_row][n_col]) continue;
                int n_height = heightMap[n_row][n_col];
                if(n_height<minBH){
                    total += (minBH - n_height);
                }
                vis[n_row][n_col] = 1;
                boundary.push({max(minBH,n_height), n_row, n_col});
            }
        }
        return total;
    }
};