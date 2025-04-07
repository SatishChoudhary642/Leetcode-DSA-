class Solution {
public:
    void per_backt(int i, vector<int>& nums, vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map <int, bool> visited;
        for(int j=i; j<nums.size(); j++){
            if(visited.find(nums[j])!=visited.end()){
                continue;
            }
            visited[nums[j]]=true;
                swap(nums[j],nums[i]);
                per_backt(i+1, nums, ans);
                swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        per_backt(0, nums, ans);
        return ans;
    }
};