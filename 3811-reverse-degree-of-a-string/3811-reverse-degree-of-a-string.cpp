class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0; i<s.size(); i++){
            ans+=(i+1)*(123-s[i]);
        }
        return ans;
    }
};