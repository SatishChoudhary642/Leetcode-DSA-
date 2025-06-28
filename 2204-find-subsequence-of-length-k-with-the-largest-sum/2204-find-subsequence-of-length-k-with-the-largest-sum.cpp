class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        vector<pair<int, int>> topk;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i], i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()>0){
            topk.push_back(pq.top());
            pq.pop();
        }
        sort(topk.begin(), topk.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });
        for(auto& i: topk){
            ans.push_back(i.first);
        }
        return ans;
    }
};