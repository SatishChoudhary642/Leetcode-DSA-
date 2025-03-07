class Solution {
public:
    int minimumChairs(string s) {
        int cnt=0, ans=0;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='E'){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt>ans){
                ans=cnt;
            }
        }
        return ans;
    }
};