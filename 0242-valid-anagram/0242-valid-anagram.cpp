class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size()){
            return false;
        }
        unordered_map <int, int> m1;
        unordered_map <int, int> m2;
        for(int i=0; i<s.size(); i++){
            m1[s[i]]++;
             m2[t[i]]++;
        }
        if(m1.size()!=m2.size()){
            return false;
        }
        for(auto i: m1){
            if(i.second!=m2[i.first]){
                return false;
            }
        }
        
        return true;
    }
};