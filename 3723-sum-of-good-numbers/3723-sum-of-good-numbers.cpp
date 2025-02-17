class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n=nums.size(), sum=0;
        for(int i=0; i<n; i++){
            if(i-k<0  && k+i>n-1){
                sum+=nums.at(i);
            }
            else if(i-k<0){
                if(nums.at(i+k)<nums.at(i)){
                    sum+=nums.at(i);
                }
            }
            else if(k+i>n-1){
                if(nums.at(i-k)<nums.at(i)){
                    sum+=nums.at(i);
                }
            }
            else if(nums.at(i+k)<nums.at(i) && nums.at(i-k)<nums.at(i)){
                sum+=nums.at(i);
            }      
        }
        return sum;
    }
};