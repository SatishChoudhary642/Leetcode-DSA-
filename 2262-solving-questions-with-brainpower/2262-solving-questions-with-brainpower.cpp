class Solution {
public:
    vector <long long> check;
    long long points_earn(int i, vector<vector<int>>& questions){
        if(i>=questions.size()){
            return 0;
        }
        if(check[i]!=-1){
            return check[i];
        }
        int next = i+questions[i][1]+1;
        long long solve=points_earn(next, questions) +questions[i][0];
        long long skip= points_earn(i+1, questions);
        return check[i]=max(skip, solve);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        long long ans, temp;
        check.resize(questions.size(), -1);
        ans=points_earn(0, questions);
        return ans;
    }
};