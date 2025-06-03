class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans=0, max=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>max){
                max=nums[i];
                ans=i;
            }
        }
        return ans;
    }
};