class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans=0, start, end, prev=1;
        sort(meetings.begin(), meetings.end());

        for(int i=0; i<meetings.size(); i++){
            start=meetings[i][0];
            end=meetings[i][1];

            if(prev<start){
                ans+=start-prev;
            }
            if(prev<end+1){
                prev=end+1;
            }
        }
        ans+=days -prev +1;
        return ans;
    }
};