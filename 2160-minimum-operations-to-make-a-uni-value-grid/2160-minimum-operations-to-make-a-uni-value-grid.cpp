class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector <int> nums;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                nums.push_back(grid[i][j]);
            }
        }
        if(nums.size()==1){ return 0;}
        sort(nums.begin(), nums.end());
        int mid=nums[nums.size()/2], ans=0;
        for(int i=0; i<nums.size(); i++){
            int diff=abs(nums[i]-mid);
            if(diff%x!=0) { return -1;}
            ans+=abs(nums[i]-mid)/x;
        }
        return ans;
    }
};