class Solution {
public:
    int possibleStringCount(string word) {
        int prev=word[0], ans=1;
        for(int i=1; i<word.size(); i++){
            if(prev==word[i]){
                ans++;
            }
            prev=word[i];
        }
        return ans;
    }
};