class Solution {
public:
    int sq(int n){
        if(n<0){
            n=-n;
        }
        return n*n;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double ans=0;
        for(int i=0; i<n; i++){
            int x1=points[i][0], x2=points[i][1];
            for(int j=i+1; j<n; j++){
                int y1=points[j][0], y2=points[j][1];
                for(int k=j+1; k<n; k++){
                    int z1=points[k][0], z2=points[k][1];
                    double a=sqrt(sq(x1-y1) + sq(x2-y2));
                    double b=sqrt(sq(y1-z1) + sq(y2-z2));
                    double c=sqrt(sq(x1-z1) + sq(x2-z2));
                    double s=(a+b+c)/2;
                    ans=max(ans, sqrt(s*(s-a)*(s-b)*(s-c)));
                }
            }
        }
        return ans;
    }
};