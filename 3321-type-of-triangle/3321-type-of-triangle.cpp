class Solution {
public:
    bool isTriangle(int a, int b, int c){
        if(a+b>c){
            return true;
        }
        return false;
    }
    string triangleType(vector<int>& nums) {
        bool tri;
        if(nums[0]>nums[1]){
            if(nums[0]>nums[2]){
                tri=isTriangle(nums[1], nums[2], nums[0]);
            }
            else{
                tri=isTriangle(nums[1], nums[0], nums[2]);
            }
        }
        else if(nums[1]>nums[2]){
            tri=isTriangle(nums[2], nums[0], nums[1]);
        }
        else{
            tri=isTriangle(nums[1], nums[0], nums[2]);
        }
        if(tri==false){
            return "none";
        }
        if(nums[0]==nums[1] && nums[1]==nums[2]){
            return "equilateral";
        }
        else if(nums[0]==nums[1] || nums[1]==nums[2] || nums[0]==nums[2]){
            return "isosceles";
        }
        return "scalene";
    }
};