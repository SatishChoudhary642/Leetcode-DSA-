class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq2;
        priority_queue<int> pq1;
        vector<long long> pre;
        vector<long long> suf;
        int n = nums.size() / 3;
        long long sum = 0, ans = LLONG_MAX;
        for (int i = 0; i < 2 * n; i++) {
            pq1.push(nums[i]);
            sum += nums[i];
            if (pq1.size() > n) {
                sum -= pq1.top();
                pq1.pop();
            }
            if (pq1.size() == n) {
                pre.push_back(sum);
            }
        }

        sum = 0;
        for (int i = nums.size()-1; i >= n; i--) {
            pq2.push(nums[i]);
            sum += nums[i];
            if (pq2.size() > n) {
                sum -= pq2.top();
                pq2.pop();
            }
            if (pq2.size() == n) {
                suf.push_back(sum);
            }
        }

    
        reverse(suf.begin(), suf.end());
        for (int i = 0; i < pre.size(); i++) {
            ans = min(ans, pre[i] - suf[i]);
        }

        return ans;
    }
};