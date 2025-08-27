class Solution {
public:
    vector<vector<int>> directions={{1,1},{1,-1},{-1,-1},{-1,1}};
    vector<vector<vector<vector<int>>>> dp;
    int find(vector<vector<int>>& grid, int i, int j, int dir, bool allow, int target){
        int ni= i + directions[dir][0];
        int nj= j + directions[dir][1];
        if(ni<0 || nj<0 || ni>=grid.size() || nj>=grid[0].size() || grid[ni][nj]!=target){
            return 0;
        }
        if(dp[ni][nj][dir][allow]!=-1){
            return dp[ni][nj][dir][allow];
        }
        int no_turn=find(grid,ni,nj,dir,allow,2-target)+1; // if 0->2-0=2 | if 2 ->2-2=0
        int turn=0;
        if(allow){
            turn=find(grid,ni,nj,(dir+1)%4,false,2-target)+1;
        }
        return dp[ni][nj][dir][allow]= max(no_turn,turn);
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans=0, n=grid.size(), m=grid[0].size();
        dp.assign(n,vector<vector<vector<int>>>(m,vector<vector<int>>(4,vector<int>(2,-1))));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    for(int dir=0; dir<=3; dir++){
                        ans=max(ans, find(grid,i,j,dir,true,2)+1);
                    }
                }
            }
        }
        return ans;
     }
}; 