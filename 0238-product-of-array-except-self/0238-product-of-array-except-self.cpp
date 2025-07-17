class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro=1;
        vector<int> suf(nums.size());
        vector <int> ans;
        for(int i=nums.size()-1; i>=0; i--){
            suf[i]=pro;
            pro*=nums[i];
        }
        pro=1;
        for(int i=0; i<nums.size(); i++){
            ans.push_back(pro*suf[i]);
            pro*=nums[i];
        }
        return ans;
    }
};