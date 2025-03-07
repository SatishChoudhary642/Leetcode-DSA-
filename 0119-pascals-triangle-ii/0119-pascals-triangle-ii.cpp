class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long  val=1;
        vector<int> ans;
        for(int j=0; j<=rowIndex;j++){
            ans.push_back(val);
            val=val*(rowIndex-j)/(j+1);
        }
        return ans;
    }
};