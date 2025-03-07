class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n=right, dif=INT_MAX, l=left, r=left+1, a=-1, b=-1;

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

        while(r<=right){
            if(prime[l]==false){
                l=r;
                r++;
            }
            else if(prime[r]==false){
                r++;
            }
            else{
                if(r-l<dif){
                    dif=r-l;
                    a=l;
                    b=r;
                }
                if(dif<=1){
                    break;
                }
                l=r;
                r++;
            }
        }
        return {a,b};
    }
};