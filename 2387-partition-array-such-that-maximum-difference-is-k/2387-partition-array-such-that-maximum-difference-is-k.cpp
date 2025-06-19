class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans=0;
        sort(nums.begin(), nums.end());

        int i=0, j=0;
        while(i<nums.size()){
            if(abs(nums[i]-nums[j])<=k){
                i++;
            }
            else{
                ans++;
                j=i;
            }
        }
        ans++;

        return ans;
    }
};