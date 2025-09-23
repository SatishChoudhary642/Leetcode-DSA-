class Solution {
public:
    void ver(vector<int>& v, string& s) {
        int j = 0;
        string n;
        for (auto c : s) {
            if (c == '.' && !n.empty()) {
                if (!n.empty()){
                        v[j] = stoi(n);
                        j++;
                        n.clear();
                    }
            } else {
                n.push_back(c);
            }
        }
        if (!n.empty())
            v[j] = stoi(n);
    }
    int compareVersion(string version1, string version2) {
        int n = 0, cnt = 0;
        for (auto a : version1)
            if (a == '.')
                n++;
        for (auto a : version2)
            if (a == '.')
                cnt++;
        n = max(n + 1, cnt + 1);
        vector<int> v1(n, 0), v2(n, 0);
        ver(v1, version1);
        ver(v2, version2);
        for (int i = 0; i < n; i++) {
            if (v1[i] < v2[i]) {
                return -1;
            } else if (v1[i] > v2[i]) {
                return 1;
            }
        }
        return 0;
    }
};