class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int b = 0, e = nums.size() - 2, m;
        if (nums.size() == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[nums.size() - 1] != nums[nums.size() - 2])
            return nums[nums.size() - 1];
        while (b <= e) {
            m = (b + e) / 2;
            if (nums[m] != nums[m + 1] && nums[m] != nums[m - 1]) {
                return nums[m];
            }
            if (nums[m] != nums[m + 1] && nums[m] != nums[m - 1]) {
                return nums[m];
            } else if (nums[m] == nums[m + 1]) {
                if (m % 2 == 0)
                    b = m + 2;
                else
                    e = m - 1;
            } else {
                if ((m - 1) % 2 == 0)
                    b = m + 1;
                else
                    e = m - 2;
            }
        }
        return -1;
    }
};