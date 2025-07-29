class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(30, 0), ans(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int bit = 0; bit < 30; bit++) {
                if ((nums[i] & (1 << bit)) > 0)
                    prev[bit] = i;
                ans[i] = max(ans[i], prev[bit] - i + 1);
            }
        }
        return ans;
    }
};