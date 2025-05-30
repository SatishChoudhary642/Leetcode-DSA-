class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_map <int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int ans, i=0;
        while(true){
            int n=(int)(pow(2, i) + 1e-9);
            if(m.count(n)==0){
                ans=n;
                break;
            }
            i++;
        }
        return ans;
    }
};