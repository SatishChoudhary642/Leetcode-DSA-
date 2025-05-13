class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector <long long>m(26, 0);
        const long long mod = 1e9 + 7;
        for(int i=0; i<s.size(); i++){
            m[s[i]-'a']++;
        }
        for(int i=1; i<=t; i++){
            vector <long long>m2(26, 0);
            for(int j=0; j<25; j++){
                if(m[j]==0)
                    continue;
                    m2[j+1]=(m2[j+1]+m[j])%mod;
            }
            if(m[25]>0){
                    m2[0]=(m2[0]+m[25])%mod;
                    m2[1]=(m2[1]+m[25])%mod;
                }

            m=m2;
        }
        
        long long ans=0;
        for(int j=0; j<m.size(); j++){
            ans=(ans+m[j])%mod;
        }
        return ans;
    }

};