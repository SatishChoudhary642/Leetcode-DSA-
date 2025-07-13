class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));
        int ans=0, p=0, t=0;
        while(p<players.size() && t<trainers.size()){
            if(players[p]<=trainers[t]){
                ans++;
                p++;
            }
            t++;
        }
        return ans;
    }
};