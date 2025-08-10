class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if ((n & (n - 1)) == 0) {
            return true;
        }
        string s = to_string(n);
        sort(s.begin(), s.end());
        for (int i = 0; i < 32; i++) {
            string num=to_string(1<<i);
            sort(num.begin(),num.end());
            if(s==num){
                return true;
            }
        }
        return false;
    }
};