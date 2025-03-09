class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int pre=colors[0], ans=0, cnt=1, n=colors.size();
        for(int i=1; i<n+k-1; i++){
            if(pre!=colors[i%n]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>=k){
                ans++;
            }
            pre=colors[i%n];
        }
        return  ans;
    }
};