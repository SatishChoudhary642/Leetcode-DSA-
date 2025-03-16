class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1, r=*max_element(ranks.begin(), ranks.end())*pow(cars,2), ans=0, n, cnt;
        long long m=(l+r)/2;
        while(l<=r){
            cnt=0;
            for(int i=0; i<ranks.size(); i++){
                n=sqrt(floor(m/ranks[i]));
                cnt+=n;
            }
            if(cnt>=cars){
                r=m-1;
            }
            else{
                l=m+1;
            }
            m=(l+r)/2;
        }
        return l;
    }
};