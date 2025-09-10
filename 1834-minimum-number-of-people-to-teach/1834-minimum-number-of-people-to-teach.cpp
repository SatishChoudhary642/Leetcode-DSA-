class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> set;
        for(int i=0; i<friendships.size(); i++){
            int u=friendships[i][0]-1;
            int v=friendships[i][1]-1;
            bool com=false;
            for(auto x: languages[u]){
                for(auto y: languages[v]){
                    if(x==y){
                        com=true;
                    }
                }
            }
            if(!com){
                set.insert(u);
                set.insert(v);
            }
        }
        unordered_map<int,int> m;
        for(auto s: set){
            for(auto x: languages[s]){
                m[x]++;
            }
        }
        int maxk=0;
        for(auto &[a,b]: m){
            maxk=max(maxk,b);
        }
        return set.size()-maxk;
    }
};