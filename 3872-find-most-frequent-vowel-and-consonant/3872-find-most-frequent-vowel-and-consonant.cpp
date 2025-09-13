class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> m;
        int ccnt = 0, vcnt = 0;
        for (auto ch : s) {
            int cnt=++m[ch];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vcnt = max(vcnt, cnt);
            } else {
                ccnt = max(ccnt, cnt);
            }
        }

        return vcnt + ccnt;
    }
};