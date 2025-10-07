class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);
        set<int> s;
        unordered_map<int, int> m;
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                s.insert(i);
            } else {
                ans[i] = -1;
                if (m.count(rains[i])) {
                    auto it = s.lower_bound(m[rains[i]]);
                    if (it == s.end()) {
                        return {};
                    }
                    ans[*it] = rains[i];
                    s.erase(it);
                }
                m[rains[i]] = i;
            }
        }
        return ans;
    }
};