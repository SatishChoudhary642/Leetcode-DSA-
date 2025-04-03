class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int max_num, n=nums.size();
        vector <int> pre_max(n);
        vector <int> suf_max(n);
        long long ans=0;

        max_num=nums[n-1];
        for(int i=n-2; i>=0; i--){
            max_num=max(max_num, nums[i+1]);
            suf_max[i]=max_num;
        }
        max_num=nums[0];
        for(int i=1; i<n-1; i++){
            max_num=max(max_num, nums[i-1]);
            pre_max[i]=max_num;
            ans=max(ans,(long long)(pre_max[i]-nums[i])*suf_max[i]);
        }
        return ans;
    }
};