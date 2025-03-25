class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int start_x, end_x, start_y, end_y, prev_x, prev_y, cnt_x=0, cnt_y=0;
        vector <vector<int>> r2;
        sort(rectangles.begin(), rectangles.end());
        prev_x=rectangles[0][0];
        for(int i=0; i<rectangles.size(); i++){
            start_x=rectangles[i][0];
            end_x=rectangles[i][2];
            if(prev_x<=start_x && prev_x < end_x){
                cnt_x++;
            }
            prev_x=max(prev_x,end_x);
            if(cnt_x==3){return true;}
            vector <int> v= {rectangles[i][1], rectangles[i][3]};
            r2.push_back(v);
        }
        sort(r2.begin(), r2.end());
        prev_y=r2[0][0];
        for(int i=0; i<r2.size(); i++){
            start_y=r2[i][0];
            end_y=r2[i][1];
            if(prev_y<=start_y && prev_y < end_y){
                cnt_y++;
            }
            prev_y=max(prev_y,end_y);
            if(cnt_y==3){return true;}
        }
        return false;
    }
};