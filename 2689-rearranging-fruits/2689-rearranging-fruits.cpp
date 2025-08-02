class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        vector<int> v1;
        vector<int> v2;
        int n=INT_MAX;
        for (int i = 0; i < basket1.size(); i++) {
            m1[basket1[i]]++;
            m2[basket2[i]]++;
            n=min({n, basket1[i], basket2[i]});
        }
        for (auto i : m1) {
            if ((i.second + m2[i.first]) % 2 != 0) {
                return -1;
            }
            auto it = m2.find(i.first);
            if (it != m2.end() && i.second > it->second) {
                v1.insert(v1.end(), (i.second - it->second)/2, i.first);
            }
        }
        for (auto i : m2) {
            if ((i.second + m1[i.first]) % 2 != 0) {
                return -1;
            }
            auto it = m1.find(i.first);
            if (it != m1.end() && i.second > it->second) {
                v2.insert(v2.end(), (i.second - it->second)/2, i.first);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        reverse(v2.begin(), v2.end());

        if (v1.size() != v2.size()) {
            return -1;
        }
        long long  ans = 0;
        for (int i = 0; i < v1.size(); i++) {
            if(v1[i] < v2[i] && v1[i]< 2*n){
                ans +=v1[i];
            }
            else if(v2[i] < v1[i] && v2[i]< 2*n){
                ans +=  v2[i];
            }
            else{
                ans+=2*n;
            }
            
        }
        return ans;
    }
};