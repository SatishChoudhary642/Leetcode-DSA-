class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        bool p=false;
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        for (int i = 0; i < words.size(); i++) {
            string a = words[i], b = words[i];
            reverse(b.begin(), b.end());
            if(a==b){
                m1[words[i]]++;
                p=true;
            }
            else{
                m2[words[i]]++;
            }
        }

        for(auto i: m1){
            if(i.second%2!=0 && p==true){
                ans++;
                p=false;
            }
            ans+=2*(i.second/2);
        }
        for (auto i : m2) {
            string a = i.first, b = i.first;
            reverse(b.begin(), b.end());
            if(m2.count(b)>0){
                ans += min(i.second, m2[b]);
            }
        }
        return 2*ans;
    }
};