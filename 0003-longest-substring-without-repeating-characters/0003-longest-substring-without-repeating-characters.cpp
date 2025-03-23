class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0, l=0;
        unordered_map <char,int> m;

        for(int r=0; r<s.size(); r++){
            m[s[r]]++; 
            while(m[s[r]]>1 && l<=r){
                m[s[l]]--;
                l++;
                if(m[s[l]]==0){
                    m.erase(s[l]);
                }
            }
            if(ans<r-l+1){
                ans=r-l+1;
            }
        }
        return ans;
    }
};