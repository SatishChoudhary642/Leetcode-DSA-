class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt, n=nums.size();
        for(int i=0; i<n; i++){
            cnt=1;
            for(int j=i+1; j<n; j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
            if(cnt > n/2){
                return nums[i];
            }
        }

        return NULL;
    }
};