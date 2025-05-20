class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map <int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        vector<vector<int>> ans;
        int s=m.size();
        while(s!=0){
            s=m.size();
            vector<int> v;
            for(auto it=m.begin(); it!=m.end();){
                if(it->second>0){
                    v.push_back(it->first);
                    m[it->first]--;
                }
                if(it->second==0){
                    s--;
                }
                ++it;
            }
            ans.push_back(v);
        } 
        return ans;
    }
};