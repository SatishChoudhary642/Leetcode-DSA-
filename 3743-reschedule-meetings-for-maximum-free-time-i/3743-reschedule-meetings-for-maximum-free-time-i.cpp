class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int pre=0;
        vector<int> gap;
        for(int i=0; i<startTime.size(); i++){
            gap.push_back(startTime[i]-pre);
            pre=endTime[i];
        }
        gap.push_back(eventTime-pre);
        int ans, len=k+1, sum=0;
        for(int i=0; i<len; i++){
            sum+=gap[i];
        }
        ans=sum;
        for(int i=len; i<gap.size(); i++){
            sum+=gap[i];
            sum-=gap[i-len];
            ans=max(ans,sum);
        }
        return ans;
    }
};