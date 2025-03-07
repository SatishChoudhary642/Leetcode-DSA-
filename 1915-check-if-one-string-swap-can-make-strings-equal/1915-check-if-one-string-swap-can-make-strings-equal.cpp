class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        if(s1==s2){
            return true;
        }
        int cnt=0, a=-1, b=-1;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(cnt==1){
                    a=i;
                }
                else if(cnt==2){
                    b=i;
                }
            }
            if(cnt>2){
                return false;
            }
        }
        if(a==-1|| b==-1){
            return false;
        }
        return (s1[a]==s2[b] && s1[b]==s2[a]) ? true : false;
    }
};