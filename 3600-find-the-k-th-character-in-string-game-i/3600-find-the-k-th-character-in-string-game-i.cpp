class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        int n=1;
        while(n<=k){
            int size=s.size();
            for(int i=0; i<size; i++){
                    s.push_back(s[i]+1);
                n++;
            }
        }
        return s[k-1];
    }
};