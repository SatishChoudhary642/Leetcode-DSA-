class Solution {
public:
    int gain(string& s, char ch1, char ch2, int n){
        stack<char> stk;
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            if(!stk.empty() && stk.top()==ch1 && s[i]==ch2){
                cnt+=n;
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        s.clear();
        while(!stk.empty()){
            s.push_back(stk.top());
            stk.pop();
        }
        reverse (s.begin(), s.end());
        return cnt;
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;
        if(x>y){
            ans+=gain(s,'a', 'b', x);
            ans+=gain(s,'b', 'a', y);
        }
        else{
            ans+=gain(s,'b', 'a', y);
            ans+=gain(s,'a', 'b', x);
        }
        return ans;
    }
};