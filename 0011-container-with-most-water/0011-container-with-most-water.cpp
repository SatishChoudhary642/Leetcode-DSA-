class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0, n=height.size();
        int l=0, r=n-1;
        while(l<=r && r<n){
            int h=min(height[r], height[l]);
            ans=max(ans, (r-l)*h);
            if(height[r] <= height[l]){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};