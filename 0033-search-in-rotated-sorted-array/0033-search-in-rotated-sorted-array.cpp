class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, m,  piv;
        int n=nums.size();
        while(l<r){
            m=(l+r)/2;
            if(nums[m]>nums[n-1]){
                l=m+1;
            }
            else if(nums[m]<nums[n-1]){
                r=m;
            }
        }
        piv=(l+r)/2;
        l=0, r=n-1;
        int rm;
        while(l<=r){
            m=(l+r)/2;
            rm=(m+piv)%n;
            if(nums[rm]==target){
                return rm;
            }
            else if(nums[rm]<target){
                l=m+1;
            }
            else if(nums[rm]>target){
                r=m-1;
            }
        }
        return -1;
    }
};