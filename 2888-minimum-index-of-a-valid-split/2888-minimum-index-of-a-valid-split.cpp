class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int x, f=0, f1, f2;
        unordered_map <int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            if(m[nums[i]]>f){
                f=m[nums[i]];
                x=nums[i];
            }
        }
        f1=0;
        f2=f;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==x){
                f1++;
                f2--;
                if(f1*2>i+1 && f2*2>(nums.size()-i-1)){
                    return i;
                }
            }

        }
        return -1;
    }
};