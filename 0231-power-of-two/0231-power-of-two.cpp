class Solution {
public:
    
    bool isPowerOfTwo(int n) {
        // if(n==0){
        //     return false;
        // }
        // while(n%2==0){
        //     n=n/2;
        // }
        // if(n==1){
        // return true;
        // }
        // return false;

        //return n>0 &&  __builtin_popcount(n)==1;
        
        return (n>0)&&(n&(n-1))==0;
    }
};