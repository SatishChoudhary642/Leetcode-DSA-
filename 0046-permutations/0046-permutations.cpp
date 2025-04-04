class Solution {
public:
    void per_backt(int i, vector<int>& nums, vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i; j<nums.size(); j++){
            swap(nums[j],nums[i]);
            per_backt(i+1, nums, ans);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        per_backt(0, nums, ans);
        return ans;
    }
};