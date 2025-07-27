class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int pre=nums[0], hill=0, valley=0;
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                continue;
            }
            if(pre<nums[i] && nums[i]>nums[i+1]){
                hill++;
            }
            else if(pre>nums[i] && nums[i]<nums[i+1]){
                valley++;
            }
            pre=nums[i];
        }
        return valley + hill;
    }
};