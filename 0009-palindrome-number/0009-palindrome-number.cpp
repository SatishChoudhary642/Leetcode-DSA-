class Solution {
public:
    bool isPalindrome(int x) {
        string num=to_string (x);
        bool ans;
        int n=num.size()
        ;
        for(int i=0; i<=n/2; i++){
            if(num[i] == num[n-i-1]){
                ans=true;
            }
            else{
                return false;
            }
        }
        return ans;
    }
};