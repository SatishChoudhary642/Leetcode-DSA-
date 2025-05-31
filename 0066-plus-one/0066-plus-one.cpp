class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n=digits.size(), carry=1;

        for(int i=n-1; i>=0; i--){
            int temp=digits[i]+carry;
            ans.push_back(temp%10);
            carry=temp/10;
        }
        if(carry!=0){
            ans.push_back(carry);
        }
        reverse (ans.begin(), ans.end());
        return ans;
    }
};