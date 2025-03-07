class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        for(int i=0; i<s.size(); i++){
            if(s[i]>=65 && s[i]<=90){
                s2.push_back(s[i] + 32);
            }
            else if((s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57)){
                s2.push_back(s[i]);
            }
        }
        int n=s2.size();
        for(int j=0; j<n/2; j++){
            if(s2[j]!=s2[n-j-1]){
                return false;
            }
        }
        return true;
    }
};