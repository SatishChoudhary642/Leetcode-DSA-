class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, buy=prices.at(0);
        for(int i=1; i<prices.size(); i++){
            if(prices[i] > buy){
                ans+=prices[i] - buy;
            }
            buy=prices[i];
        }
        return ans;
    }
};