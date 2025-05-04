class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map <string, int> m;
        int ans=0;
        for(int i=0; i<dominoes.size(); i++){
            string s= to_string(dominoes[i][0]) + to_string(dominoes[i][1]);
            string rs=s ;
            reverse(rs.begin(), rs.end());
            if (m.count(rs)>0){
                m[rs]++;
            }
            else{
                m[s]++;
            }
        }
        for(auto &i: m){
            ans+=((i.second)*(i.second-1))/2;
        }
        return ans;
    }
};