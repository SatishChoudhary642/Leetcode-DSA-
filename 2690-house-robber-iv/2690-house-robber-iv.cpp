class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int r=*max_element(nums.begin(),nums.end()), l=1;
        int m=(l+r)/2, cnt=0;
        while(l<r){
            m=(l+r)/2, cnt=0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]<=m){
                    cnt++;
                    i++;
                }
            }
            if(cnt>=k){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        return l;
    }
};