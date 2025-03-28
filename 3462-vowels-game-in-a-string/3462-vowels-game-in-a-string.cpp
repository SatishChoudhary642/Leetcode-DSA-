class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                cnt++;
            }
        }
        if(cnt==0){ return false;}
        return true;
    }
};