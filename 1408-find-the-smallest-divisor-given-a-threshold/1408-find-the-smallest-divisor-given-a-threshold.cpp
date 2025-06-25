class Solution {
public:
    int div(int a, int b){
        if(a%b==0){
            return a/b;
        }
        return a/b +1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int sum=0, ans=INT_MAX;
        int b=1, e=*max_element(nums.begin(), nums.end());
        while(e>=b){
            int m=(b+e)/2;
            sum=0;
            for(int i=0; i<nums.size(); i++){
                sum+=div(nums[i], m);
                // sum += (nums[i] + m - 1) / m;
            }
            if(sum<=threshold){
                ans=min(ans, m);
                e=m-1;
            }
            else{
                b=m+1;
            }
        }
        return ans;
    }
};