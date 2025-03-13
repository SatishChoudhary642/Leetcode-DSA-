class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0,  cnt= 0;
        vector<int> arr(n + 1);

        for (int i = 0; i < n; i++) {
            while (sum + arr[i] < nums[i]) {
                cnt++;
                if (cnt > queries.size()) return -1;

                int l = queries[cnt - 1][0], r = queries[cnt - 1][1], v = queries[cnt - 1][2];
                if (r >= i) {
                    arr[max(l, i)] += v;
                    if (r + 1 < arr.size()) {
                        arr[r + 1] -= v;
                    }
                }
            }
            sum += arr[i];
        }
        return cnt;
    }
};
