class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size(), sum1=nums[0], sum2=0;
        int diff, cnt=0;
        for(int i=1; i<n; i++){
            sum2= sum2 + nums[i];
        }

        for(int j=1; j<n; j++){
            diff=sum1 - sum2;
            if(diff % 2==0){
                cnt++;
            }
            sum1=sum1 + nums[j];
            sum2=sum2 - nums[j];
        }
        return cnt;
    }
};