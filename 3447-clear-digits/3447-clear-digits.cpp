class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i]>=65){
                ans.push_back(s[i]);
            }
            else if(s[i]<=57){
                ans.pop_back();
            }
        }
        return ans;
    }
};