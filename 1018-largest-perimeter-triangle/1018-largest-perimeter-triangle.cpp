class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(), nums.end());
        for(int i=n-1; i>=2; i--){
            int a=nums[i], b=nums[i-1], c=nums[i-2];
            if(a<b+c){
                ans=max(ans, a+b+c);
            }
        }
        return ans;
    }
};