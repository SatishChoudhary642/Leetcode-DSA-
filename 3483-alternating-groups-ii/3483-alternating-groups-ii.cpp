class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int pre=colors[0], ans=0, cnt=1;
        for(int i=1; i<colors.size(); i++){
            if(pre!=colors[i]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>=k){
                ans++;
            }
            pre=colors[i];
        }
        for(int i=0; i<k-1; i++){
            if(pre!=colors[i]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>=k){
                ans++;
            }
            pre=colors[i];
        }
        return  ans;
    }
};