class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1, min=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<=min){
                min=nums[i];
            }
            else{
                ans=max(ans, nums[i]-min);
            }
            
        }
        return ans;
    }
};