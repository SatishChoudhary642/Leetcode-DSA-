class Solution {
public:
    void com_backt(int i, int n, int k, vector<int>& arr, vector<vector<int>>& ans){
        if(arr.size()==k){
            ans.push_back(arr);
            return;
        }
        for(int j=i; j<=n; j++){
            arr.push_back(j);
            com_backt(j+1, n, k, arr, ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        vector<vector<int>> ans;
        com_backt(1, n, k, arr, ans);
        return ans;
    }
};