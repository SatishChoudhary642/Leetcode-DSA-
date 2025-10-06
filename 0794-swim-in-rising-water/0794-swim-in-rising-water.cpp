class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ans=0, n=grid.size();
        vector<vector<int>> d={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> v (n, vector<int>(n,0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        v[0][0]=1;
        while(!pq.empty()){
            int p=pq.top()[0], x=pq.top()[1], y=pq.top()[2];
            pq.pop();
            if(x==n-1 && y==n-1){
                return p;
            }
            for(int i=0; i<4; i++){
                int x1=x+ d[i][0], y1= y+ d[i][1];
                if(x1>=0 && x1<n && y1>=0 && y1<n && !v[x1][y1]){
                    pq.push({max(p,grid[x1][y1]), x1, y1});
                    v[x1][y1]=1;
                }
            }
        }
        
        return -1;
    }
};