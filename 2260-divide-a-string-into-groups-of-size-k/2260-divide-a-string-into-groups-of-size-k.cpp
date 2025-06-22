class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int carry=s.size()%k, cnt=0;
        vector<string> ans;
        string ss;
        for(int i=0; i<s.size(); i++){
            ss.push_back(s[i]);
            cnt++;
            if(cnt==k){
                ans.push_back(ss);
                cnt=0;
                ss.erase();
            }
        }
        if(carry==0){
            return ans;
        }
        while(carry<k){
            ss.push_back(fill);
            carry++;
        }
        ans.push_back(ss);
        return ans;
    }
};