class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles;
        int b=numBottles, n=numExchange, f=0;
        while(b>=n){
            if(f>0){
                ans+=f;
                f=0;
            }
            else{
                f++;
                b=b-n+1;
                n++;
            }
        }
        ans+=f;
        return ans;
    }
};