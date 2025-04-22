class Solution {
public:
    unordered_map<int, int> mem;
    int dp_sol(int sum, int n){
        if(sum==n){
            return 1;
        }
        else if(sum>n){
            return 0;
        }
        if (mem.count(sum)) return mem[sum];

        mem[sum] = dp_sol(sum + 1, n) + dp_sol(sum + 2, n);
        return mem[sum];
    }
    int climbStairs(int n) {
        return dp_sol(0, n);
    }
};