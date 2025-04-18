class Solution {
public:
    
    string countAndSay(int n) {
        string s="1";
        for(int j=1; j<n; j++){
            string s2;
            char ch=s[0];
            int cnt=1;
            for(int i=1; i<s.size(); i++){
                if(ch==s[i]){
                    cnt++;
                }
                else{
                    s2+=to_string(cnt);
                    s2.push_back(ch);
                    ch=s[i];
                    cnt=1;
                }
            }
            s2+=to_string(cnt);
            s2.push_back(ch);
            s=s2;
        }
        return s;
    }
};