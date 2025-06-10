class Solution {
public:
    int maxDifference(string s) {
        unordered_map <char, int> m;
        int odd=INT_MIN, even=INT_MAX;

        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        for(auto i: m){
            if(i.second%2==0){
                even=min(even, i.second);
            }
            else{
                odd=max(odd, i.second);
            }
        }
        return odd-even;
    }
};