class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans=0, n=colors.size(), l=0, r=2, m=1;
        while(l<n){
            if(colors[m]==1){
                if(colors[l]==0 && colors[r]==0){
                    ans++;
                }
            }
            else if(colors[m]==0){
                if(colors[l]==1 && colors[r]==1){
                    ans++;
                }
            }
            l++; m++; r++;
            if(r==n){
                r=0;
            }
            if(m==n){
                m=0;
            }
        }
        return ans;
    }
};