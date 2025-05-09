class Solution {
public:
    bool check_pal(string num){
        for(int i=0; i<num.size(); i++){
            if(num[i]!=num[num.size()-1])
                return false;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        for(int i=2; i<n-1; i++){
            string num;
            int temp=n;
            while(temp!=0){
                num.push_back('0'+temp%i);
                temp/=i;
            }
            if(!check_pal(num)){
                return false;
            }
        }
        return true;
    }
};