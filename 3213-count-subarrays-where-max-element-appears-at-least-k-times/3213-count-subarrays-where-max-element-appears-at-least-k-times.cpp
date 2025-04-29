class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int cnt=0, n=*max_element(nums.begin(), nums.end());
        int l=0, r=0;
        long long ans=0;
        for(int r=0; r<nums.size(); r++){
            if(nums[r]==n){
                cnt++;
            }
            while(cnt>=k){
                if(nums[l]==n){
                    cnt--;
                }
                l++;
            }
            ans+=l;
        }
        return ans;
    }
};