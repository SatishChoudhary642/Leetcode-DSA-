class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0, pro=1;
        while(n!=0){
            sum+=(n%10);
            pro*=(n%10);
            n=n/10;
        }
        return pro-sum;
    }
};