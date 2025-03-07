class Solution {
public:
    bool check(string s, int a, int b){
        while(a<=b){
            if(s[a]==s[b]){
                a++;
                b--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        stack<int> st;
        int i=0,j=n-1, cnt=0;;
        while (i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
                continue;
            }
            else if (cnt==0){
                if(check(s,i+1,j)){
                    i++;
                }
                else if(check(s,i,j-1)){
                    j--;
                }
                cnt++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};