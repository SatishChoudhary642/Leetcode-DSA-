class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int ans=0, pre=0;
        vector<int> gap;
        for(int i=0; i<startTime.size(); i++){
            gap.push_back(startTime[i]-pre);
            pre=endTime[i];
        }
        gap.push_back(eventTime - pre);

        for(int i=0; i<gap.size()-1; i++){
            ans=max(ans, gap[i]+gap[i+1]);
        }

        vector <int> sgap=gap;
        sort(sgap.rbegin(), sgap.rend());
        int top1=sgap[0], top2=sgap[1], top3=sgap[2];

        for(int i=0; i<startTime.size(); i++){
            int lgap=gap[i];
            int rgap=gap[i+1];
            int mx=max(lgap, rgap), mn=min(lgap, rgap);
            int event=endTime[i] - startTime[i];
            bool s1=false, s2=false;
            if(mx!=top1){
                s1=true;
            }
            else if(mn!=top2){
                s2=true;
            }

            if((s1 && top1>=event) || (s2 && top2>=event) || (top3>=event)){
                ans=max(ans, rgap+lgap+event);
            }
        }
        return ans;
    }
};