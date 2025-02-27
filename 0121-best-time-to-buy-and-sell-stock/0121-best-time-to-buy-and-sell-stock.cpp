class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0, buy=prices.at(0), sell;
        for(int i=1; i<prices.size(); i++){
            if(prices.at(i)<buy){
                buy=prices.at(i);
            }
            else if(prices.at(i) - buy >res){
                res=prices.at(i) - buy;
            }
        }
        return res;
    }
};