class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> pre1(n, -1);
        vector<int> ans;
        int i = 0, cnt = 0;
        while (s[i] != '|' && i < n) {
            i++;
        }
        while (i < n) {
            if (s[i] == '|') {
                pre1[i] = cnt;
            } else {
                cnt++;
            }
            i++;
        }
        vector<int> pre2= pre1;
        int val=0;
        for(int i=0; i<n; i++){
            if(pre1[i]==-1){
                pre1[i]=val;
            }
            else{
                val=pre1[i];
            }
         }
        val=0;
        for(int i=n-1; i>=0; i--){
            if(pre2[i]==-1){
                pre2[i]=val;
            }
            else{
                val=pre2[i];
            }
        }
        
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            if(pre1[l]==pre1[r] && pre2[l]==pre2[r]){
                ans.push_back(0);
            }
            else{
                ans.push_back(pre1[r] - pre2[l]);
            }
            
        }
        return ans;
    }
};