class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map <int, int> m;
        vector<int> ans;
        for(int i=0; i<A.size(); i++){
            m[A[i]]++;
            m[B[i]]++;
            int cnt=0;
            for(auto &i: m){
                if(i.second==2){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};