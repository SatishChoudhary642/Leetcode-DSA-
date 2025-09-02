class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        sort(points.begin(),points.end(),[]
            (auto&a,auto&b){
                if(a[0]!=b[0]) return a[0]>b[0];
                return a[1]<b[1];
            }
            );
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                if(x1<x2 || y1>y2){
                    continue;
                }
                int valid=1;
                for(int k=i+1;k<j;k++){
                int x3=points[k][0];
                int y3=points[k][1];
                if(x2<=x3 && y2>=y3 
                  && x1>=x3 && y1<=y3){
                    valid=0;
                    break;
                  }
                }
                ans+=valid;
            }
        }
        return ans;
    }
};