class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l=0, r=k-1, ans, W=0;
        for(int i=0; i<k; i++){
            if(blocks[i]=='W'){
                W++;
            }
        }
        ans=W;
        while(r<blocks.size()){
            ans=min(W,ans);
            if(blocks[l]=='W'){
                W--;
            }
            l++; r++;
            if(blocks[r]=='W'){
                W++;
            }
        }
        return ans;
    }
};