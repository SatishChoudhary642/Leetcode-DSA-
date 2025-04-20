class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
        unordered_map <int, int> m;
        for(int i=0; i<answers.size(); i++){
            m[answers[i]]++;
        }
        for(auto i: m){
            int rab=i.second;
            int color=i.first;
            if(color==0){
                ans+=rab;
                continue;
            }
            if(rab>color+1){
                ans+=((color+1)*((rab+color)/(color+1)));
            }
            else {
                ans+=color+1;
            }
        }
        return ans;
    }
};