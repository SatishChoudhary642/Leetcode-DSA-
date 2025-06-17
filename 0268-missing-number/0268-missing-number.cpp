class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> n(nums.size()+1, false);
        int ans;
        
        for(int i=0; i<nums.size(); i++){
            n[nums[i]]=true;
        }
        for(int i=0; i<n.size(); i++){
            if(n[i]==false){
                ans=i;
                break;
            }
        }
        return ans;
    }
};