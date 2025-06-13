class Solution {
public:
    bool isVowel(char c){
        char ch=tolower(c);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        vector<char> vow;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                vow.push_back(s[i]);
            }
        }
        
        reverse(vow.begin(), vow.end());
        int j=0;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                s[i]=vow[j];
                j++;
            }
        }
        return s;
    }
};