class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long r=*max_element(candies.begin(),candies.end()), l=1, sum=0, ans=0;
        long long m=(r+l)/2;
        while(l<=r){
            for(int i=0; i<candies.size(); i++){
                sum+=candies[i]/m;
            }

            if(sum>=k){
                ans=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
            m=(r+l)/2;
            sum=0;
        }
        return ans;
    }
};