class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int res=0;
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1; i<words.size(); i++){
            if(groups[res]!=groups[i]){
                ans.push_back(words[i]);
                res=i;
            }
        }
        return ans;
    }
};