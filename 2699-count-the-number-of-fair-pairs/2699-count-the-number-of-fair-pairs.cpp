class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        long long l=0, r=n-1, sum, low=0, up=0;

            while(l<r){
                sum=nums[l]+nums[r];
                if(sum>=upper+1){
                    up+=(r-l);
                    r--;
                }
                else{
                    l++;
                }
            }
            l=0, r=n-1;
            while(l<r){
                sum=nums[l]+nums[r];
                if(sum>=lower){
                    low+=(r-l);
                    r--;
                }
                else{
                    l++;
                }
            }
        return low-up;
    }
};