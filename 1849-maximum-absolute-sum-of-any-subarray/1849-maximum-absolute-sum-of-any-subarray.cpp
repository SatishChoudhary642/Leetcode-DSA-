class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_res=nums.at(0), min_res=nums.at(0), min_sum=nums.at(0), max_sum=nums.at(0);
        for(int i=1; i<nums.size(); i++){
            max_sum=max(max_sum + nums.at(i), nums.at(i));
            max_res=max(max_sum, max_res);
            min_sum=min(min_sum + nums.at(i), nums.at(i));
            min_res=min(min_sum, min_res);
        }
        return max(max_res, abs(min_res));
    }
};