class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n=right, dif=INT_MAX, 
        l=right-1, r=right, a=-1, b=-1;
        vector <bool> prime(n+1, true);
        prime[1]=false;
        prime[0]=false;
        for(int i=2; i*i<=n; i++){
            if(prime[i]){
                for(int j=i*i; j<=n; j+=i){
                        prime[j]=false;
                }
            }
        }
        while(l>=left){
            if(prime[r]==false){
                r=l;
                l--;
            }
            else if(prime[l]==false){
                l--;
            }
            else{
                if(r-l<=dif){
                    dif=r-l;
                    a=l;
                    b=r;
                }
                r=l;
                l--;
            }
        }
        return {a,b};
    }
};