class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg= 0, end= nums.size()-1, mid;
        mid=((beg + end)/2);

        while(beg<=end  && nums[mid]!=target){
            if(nums[mid]<target){
                beg=mid+1;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            mid=((beg + end)/2);
        }
        if(nums[mid]==target){
            return mid;
        }
        else if(target <nums[0]){
            return 0;
        }
        else{
            return mid+1;
        }
    }
};