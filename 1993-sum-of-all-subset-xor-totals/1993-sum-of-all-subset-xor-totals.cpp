class Solution {
public:
    void XORsubset(int i, vector<int>& nums, vector<int> subset, vector<vector<int>>& set){
        if(i== nums.size()){
            set.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        XORsubset(i+1, nums, subset, set);
        subset.pop_back();
        XORsubset(i+1, nums, subset, set);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> set;
        int sum=0,XOR;
        XORsubset(0, nums, subset, set);
        for(int i=0; i<set.size(); i++){
            if(set[i].size()!=0){
                XOR=set[i][0];
            }
            else{
                XOR=0;
            }
            for(int j=1; j<set[i].size(); j++){
                XOR=XOR^set[i][j];
            }
            sum+=XOR;
        }
        return sum;
    }
};