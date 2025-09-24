class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string ans;
        if((numerator<0)^(denominator<0)){
            ans.push_back('-');
        }
        long long dividend = llabs(numerator);
        long long divisor = llabs(denominator);
        ans+=to_string(dividend/divisor);
        long long rem=dividend % divisor;
        if(rem==0){
            return ans;
        }
        ans.push_back('.');

        unordered_map<long long, int> m;
        while(rem!=0){
            if(m.count(rem)){
                ans.insert(m[rem],"(");
                ans+= ")";
                break;
            }
            m[rem]=ans.size();
            rem*=10;
            ans+= to_string(rem/divisor);
            rem%=divisor;
        }
        return ans;
    }
};