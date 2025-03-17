class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int cnt=0, n=nums.size()/2;
        unordered_map <int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        for(auto i=m.begin(); i!=m.end(); i++){
            if((i->second)%2==0){
                cnt+=(i->second)/2;
            }

        }
        if(cnt==n){
            return true;
        }
        return false;
    }
};