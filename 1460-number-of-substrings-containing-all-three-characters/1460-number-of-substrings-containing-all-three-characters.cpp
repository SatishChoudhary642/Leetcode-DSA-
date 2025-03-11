class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0, ans=0, n=s.size();
        unordered_map <char, int> m;
        for(int r=0; r<n; r++){
            m[s[r]]++;
            while(m.size()==3){
                ans+=n-r;
                m[s[l]]--;
                if(m[s[l]]==0){
                    m.erase(s[l]);
                }
                l++;
            }
        }
        return ans;
    }
};