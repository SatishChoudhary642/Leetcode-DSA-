class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0, r=0, bit=0, ans=1;
        while(r<nums.size()){
                while((bit & nums[r])!=0){
                    bit^=nums[l];
                    l++;
                }
            bit|=nums[r];
            if((r-l)+1>ans){
                    ans=(r-l)+1;
                }
            r++;
        }
        return ans;
    }
};