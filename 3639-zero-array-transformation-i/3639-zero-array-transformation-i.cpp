class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector <int> arr (nums.size() +1, 0);
        int l, r, sum=0;
        
        for(int i=0; i<queries.size(); i++){
            l=queries[i][0];
            r=queries[i][1];
            arr[l]++;
            arr[r+1]--;
        }
        for(int i=0; i<nums.size(); i++){
            sum+=arr[i];
            if(sum<nums[i]){
                return false;
            }
        }
        return true;
    }
};