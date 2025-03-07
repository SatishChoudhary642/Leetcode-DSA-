class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool c;
        if(nums[0]%2==0){
            c=true;
        }
        else{
            c=false;
        }

        for(int i=1; i<nums.size(); i++){
            if(nums[i]%2 !=0 && c== false){
                return false;
            }
            else if(nums[i]%2 ==0 && c== true){
                return false;
            }
            else if(nums[i]%2 !=0 && c== true){
                c=false;
                continue;
            }
            c=true;
        }
        return true;
    }
};