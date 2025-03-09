class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans=0, n=colors.size(), l=0, r=2, m=1;
        while(l<n){
            if(colors[m]!=colors[l] && colors[m]!=colors[r]){
                    ans++;
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