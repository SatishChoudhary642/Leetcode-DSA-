class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n1=nums.size();
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]==nums[i] ){
                nums[i-1]=2*nums[i-1];
                nums[i]=0;
            }
        }
        nums.erase(remove(nums.begin(), nums.end(),0), nums.end());
        int n2=nums.size();
        nums.insert(nums.end(),n1-n2, 0);
        return nums;
    }
};