class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = -1;
        for (int i = 1; i < nums.size(); i++) {
            ans = max(ans, abs(nums[i - 1] - nums[i]));
        }
        return max(ans, abs(nums[0] - nums[nums.size() - 1]));
    }
};