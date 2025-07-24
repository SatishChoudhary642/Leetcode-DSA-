class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        priority_queue <int, vector<int>, greater<int>> pq; 
        int ans=1, cnt=1;
        for(int i=0; i<nums.size(); i++){
           pq.push(nums[i]);
        }
        int pre=pq.top();
        pq.pop();
        while(!pq.empty()){
            if(pq.top()==pre){
                pq.pop();
                continue;
            }
            else if(pq.top()==pre+1){
                cnt++;
                pre=pq.top();
                pq.pop();
            }
            else{
                
                cnt=1;
                pre=pq.top();
                pq.pop();
            }
            ans=max(ans, cnt);
        }
        return ans;
    }
};