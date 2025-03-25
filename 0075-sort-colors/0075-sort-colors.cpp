class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0, white=0, blue=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                red++;
            }
            else if(nums[i]==1){
                white++;
            }
            else if(nums[i]==2){
                blue++;
            }
        }
        nums.clear();
        nums.insert(nums.begin(), red, 0);
        nums.insert(nums.begin() + red, white, 1);
        nums.insert(nums.begin() + red + white, blue, 2);
    }
};