class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans=-1;
        for(int i=1; i<nums.size(); i++){
            ans=max(nums[i]-nums[i-1], ans);
        }
        return ans;
    }
};