class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long ln=n;
        if(ln<0){
            ln=(-1)*ln;
        }
        while(ln>0){
            if(ln%2==1){
                ans=ans*x;
                ln=ln-1;
            }
            else{
                x=x*x;
                ln=ln/2;
            }
        }
        if(n<0){
            ans=1.0/ans;
        }
        return ans;
    }
};