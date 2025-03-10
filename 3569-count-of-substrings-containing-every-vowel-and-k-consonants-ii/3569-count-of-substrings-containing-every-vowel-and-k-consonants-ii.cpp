class Solution {
public:
    long long fun(string word, int k){
        int cnt=0, l=0, r=0;
        long long ans=0;
        unordered_map <char,int> m;
        while(r<word.size()){
            if(word[r]=='a' || word[r]=='e' || word[r]=='i' 
               || word[r]=='o' || word[r]=='u'){
                m[word[r]]++;
            }
            else{
                cnt++;
            }
            while((m['a']>=1 && m['e']>=1 && m['i']>=1 && m['o']>=1 && m['u']>=1 && cnt>=k)){
                ans+=word.size() -r;
                if(word[l]=='a' || word[l]=='e' || word[l]=='i' 
                    || word[l]=='o' || word[l]=='u'){
                    m[word[l]]--;
                    if(m[word[l]]==0){
                        m.erase(word[l]);
                    }
                }
                else{
                    cnt--;
                }
                l++;
            }
            r++;

        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return fun(word, k) - fun(word, k+1);
    }
};