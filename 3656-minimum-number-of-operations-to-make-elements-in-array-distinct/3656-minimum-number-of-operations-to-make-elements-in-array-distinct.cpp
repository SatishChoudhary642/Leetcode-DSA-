class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> set;
        int i;
        for(i=nums.size()-1; i>=0; i--){
            if(set.find(nums[i])!=set.end()){
                break;
            }
            set.insert(nums[i]);
        }
        if((i+1)%3==0){
            return (i+1)/3;
        }
        return (i+1)/3 +1;
    }
};