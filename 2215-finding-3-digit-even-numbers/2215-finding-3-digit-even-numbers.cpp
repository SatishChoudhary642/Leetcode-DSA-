class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;

        for(int i=0; i<digits.size(); i++){
            if(digits[i]==0)
                continue;
            for(int j=0; j<digits.size(); j++){
                if(i==j)
                    continue;
                for(int k=0; k<digits.size(); k++){
                    if(i==k || j==k)
                        continue;
                    int n=(digits[i]*100) + (digits[j]*10) + digits[k];
                    if(n%2!=0)
                        continue;
                    ans.push_back(n);
                }
            }
        }

        sort(ans.begin(), ans.end());
        auto it=unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());
        return ans;
    }
};