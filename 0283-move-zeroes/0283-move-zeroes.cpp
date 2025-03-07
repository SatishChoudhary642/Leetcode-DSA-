class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n1=nums.size();
        nums.erase(std::remove(nums.begin(), nums.end(), 0), nums.end());
        int n2=nums.size();
        int t=n1-n2;
        nums.insert(nums.begin() + n2,t,0);
    }
};