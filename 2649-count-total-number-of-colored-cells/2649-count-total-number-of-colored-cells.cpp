class Solution {
public:
    long long coloredCells(int n) {
        return 1+ (2*(pow(n,2)-n));
    }
};