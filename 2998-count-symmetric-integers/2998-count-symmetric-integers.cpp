class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low; i<=high; i++){
            string n=to_string(i);
            int left=0, right=0;
            for(int j=0; j<n.size(); j++){
                if(j<n.size()/2){
                    left+=n[j];
                }
                else{
                    right+=n[j];
                }
            }
            if(left==right){
                cnt++;
            }
        }
        return cnt;
    }
};