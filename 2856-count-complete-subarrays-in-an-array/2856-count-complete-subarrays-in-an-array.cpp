class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map <int, int> m;
        int cnt, ans=0;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        cnt=m.size();
        m.clear();
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                m[nums[j]]++;
                if(m.size()==cnt){
                    ans++;
                }
            }
            for(int j=nums.size()-1; j>=i; j--){
                m[nums[j]]--;
                if(m[nums[j]]==0){
                    m.erase(nums[j]);
                }
            }
        }
        return ans;
    }
};