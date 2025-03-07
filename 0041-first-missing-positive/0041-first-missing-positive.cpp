class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt=1, n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                if(nums[i]==cnt){
                    cnt++;
                }
                else if(nums[i]==cnt+1){
                    return cnt;
                }
            }
        }
        return cnt;
    }
};