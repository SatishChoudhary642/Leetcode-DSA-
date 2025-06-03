class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.push_back(INT_MIN);
        nums.insert(nums.begin(), INT_MIN);
        int beg=1, end=nums.size()-2, ans;
        
        while(beg<=end){
            int mid=(beg+end)/2;
            if(nums[mid]<nums[mid-1]){
                end=mid-1;
            }
            else if(nums[mid]<nums[mid+1]){
                beg=mid+1;
            }
            else{
                ans=mid;
                break;
            }
        }
        return ans-1;
    }
};