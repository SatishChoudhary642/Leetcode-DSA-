class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        for(int i=0; i<words.size(); i++){
            unordered_map <char, int> m;
            for(int i=0; i<chars.size(); i++){
                m[chars[i]]++;
            }
            bool sign=true;
            for(int j=0; j<words[i].size(); j++){
                if(m[words[i][j]]>0){
                    m[words[i][j]]--;
                }
                else{
                    sign=false;
                    break;
                }
            }
            if(sign==true){
                ans+=words[i].size();
            }
        }
        return ans;
    }
};