class Solution {
public:
    string reverseWords(string s) {
        string ans, t;

        bool b=false;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                if(t.empty()){
                    continue;
                }
                if(b==false){
                    ans=t;
                    b=true;
                }
                else{
                    ans=t + " " +ans;
                }
                t.erase();
            }
            else{
                t.push_back(s[i]);
            }
        }
        if(!t.empty() && !ans.empty()){
            ans=t + " " +ans;
        }
        else{
            ans=ans+t;
        }
        
        return ans;
    }
};