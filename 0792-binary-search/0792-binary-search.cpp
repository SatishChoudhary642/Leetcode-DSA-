class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int beg=0, end=n-1;
        int mid=(beg + end )/2;
        while(beg<=end && nums[mid]!=target){
            if(nums[mid]<=target){
                beg=mid+1;
            }
            else if(nums[mid]>=target){
                end=mid-1;
            }
            mid=(beg + end)/2;
        }
        return (nums[mid]==target) ? mid : -1;
    }
};