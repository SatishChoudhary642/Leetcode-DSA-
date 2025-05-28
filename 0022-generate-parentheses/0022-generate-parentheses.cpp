class Solution {
public:
    void bkt_p(int i, int j, int n, string& s, vector<string>& ans){
        if(i==n && j==n){
            ans.push_back(s);
            return;
        }

        if(i<n){
            s.push_back('(');
            bkt_p(i+1, j, n, s, ans);
            s.pop_back();
        }
        
        if(j < i){
            s.push_back(')');
            bkt_p(i, j+1, n, s, ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        bkt_p(0,0,n,s,ans);
        return ans;
    }
};