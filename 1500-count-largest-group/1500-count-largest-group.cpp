class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> m;
        for(int i=1; i<=n; i++){
            string s=to_string(i);
            int sum=0;
            for(int j=0; j<s.size(); j++){
                sum+=s[j] -'0';
            }
            m[sum]++;
        }
        int max=-1, ans=0;
        for(auto i:m){
            if(i.second>max){
                max=i.second;
                ans=1;
            }
            else if(i.second==max){
                ans++;
            }
        }
        return ans;
    }
};