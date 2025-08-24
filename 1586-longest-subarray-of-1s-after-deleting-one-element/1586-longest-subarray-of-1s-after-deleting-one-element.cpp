class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0, cnt=0,l=0;
        for(int r=0; r<nums.size(); r++){
            if(nums[r]==0) cnt++;
            while(cnt>1 && l<=r){
                if(nums[l]==0) cnt--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans-1;
    }
};