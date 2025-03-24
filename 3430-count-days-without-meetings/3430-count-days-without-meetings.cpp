class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // vector <bool> work (days+1, false);
        // int start, end, ans=0;
        // for(int i=0; i<meetings.size(); i++){
        //     int start=meetings[i][0], end=meetings[i][1];
        //     fill(work.begin()+start, work.begin()+end +1, true); // used +1 because it changes values before end and not till end+1
        // }
        // for(int j=1; j<work.size(); j++){
        //     if(work[j]==false){
        //         ans++;
        //     }
        // }
        // return ans;

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