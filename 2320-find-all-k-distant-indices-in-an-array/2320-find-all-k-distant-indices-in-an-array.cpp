class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int top=-1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==key){
                for(int j=0; j<nums.size(); j++){
                    if(j>top && abs(i-j)<=k){
                        ans.push_back(j);
                        top=j;
                    }
                }
            }
        }
        return ans;

    }
};