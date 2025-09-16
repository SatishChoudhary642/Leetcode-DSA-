class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        for(auto n: nums){
            s.push(n);
            while (s.size() >= 2) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int g=__gcd(a, b);
                if (g > 1) {
                    s.push(lcm(a, b));
                } else {
                    s.push(b);
                    s.push(a);
                    break;
                }
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse (ans.begin(), ans.end());
        return ans;
    }
};
