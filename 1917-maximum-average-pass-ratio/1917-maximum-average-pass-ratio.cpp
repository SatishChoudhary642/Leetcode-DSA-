class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue <pair<double,int>> pq;
        for(int i=0; i<n; i++){
            int pass=classes[i][0], total=classes[i][1];
            double diff=((double)(pass+1)/(total+1))-((double)pass/total);
            pq.push({diff,i});
        }
        for(int i=1; i<=extraStudents; i++){
            pair<double,int> p=pq.top();
            pq.pop();
            int idx=p.second;
            classes[idx][0]++;
            classes[idx][1]++;
            int pass=classes[idx][0], total=classes[idx][1];
            double diff=((double)(pass+1)/(total+1))-((double)pass/total);
            pq.push({diff,idx});
        }

        double ans=0;
        for(int i=0; i<n; i++){
            ans+=(double)classes[i][0]/classes[i][1];
        }
        return ans/n;
    }
};