class Solution {
public:
    void per_backt(int i, string& nums, vector<string>& permu) {
        if (i == nums.size()) {
            permu.push_back(nums);
            return;
        }
        unordered_map<char, bool> visited;
        for (int j = i; j < nums.size(); j++) {
            if (visited.find(nums[j]) != visited.end()) {
                continue;
            }
            visited[nums[j]] = true;
            swap(nums[j], nums[i]);
            per_backt(i + 1, nums, permu);
            swap(nums[j], nums[i]);
        }
    }
    bool reorderedPowerOf2(int n) {
        if ((n & (n - 1)) == 0) {
            return true;
        }
        vector<string> permu;
        string s = to_string(n);
        per_backt(0, s, permu);
        for (int i = 0; i < permu.size(); i++) {
            int num = stoi(permu[i]);
            if(permu[i].size()!=to_string(num).size()){
                continue;
            }
            if (num > 0 && (num & (num - 1)) == 0) {
                return true;
            }
        }
        return false;
    }
};