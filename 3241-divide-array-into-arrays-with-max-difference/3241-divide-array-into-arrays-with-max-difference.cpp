class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int res=nums[0], cnt=0;
        vector<int> v;
        for(int i=0; i<nums.size(); i++){ 
            if(cnt==3){
                ans.push_back(v);
                
                v.clear();
                cnt=0;
            }
            v.push_back(nums[i]);
            cnt++;
            res=nums[i];
        }
        ans.push_back(v);
        for(int i=0; i<ans.size(); i++){
            if(abs(ans[i][0]-ans[i][1])>k ||
                 abs(ans[i][1]-ans[i][2])>k || 
                 abs(ans[i][0]-ans[i][2])>k){
                    return {};
            }
        }
        return ans;
    }
};