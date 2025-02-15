class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1, n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n && n>2; i++){
            if(nums[i+1]==nums[i]){
                cnt++;
                if(cnt>n/2){
                    return nums[i];
                }
            }
            else if(nums[i+1]!=nums[i]){
                cnt=1;
            }
        }
        return nums[0];
    }
};