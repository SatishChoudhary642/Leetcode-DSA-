class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sum=0, cnt=0;
        for(int i=0; i+2<nums.size(); i++){
            if(nums[i]==0){
                nums[i]=1-nums[i];
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];
                cnt++;
            }
            sum++;
        }
        sum+=nums[nums.size()-1];
        sum+=nums[nums.size()-2];
        return (sum==nums.size()) ? cnt : -1;
    }
};