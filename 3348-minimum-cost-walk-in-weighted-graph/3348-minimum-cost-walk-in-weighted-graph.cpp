class Solution {
public:
    vector <int> parent;
    vector <int> min;

    int find(int node){
        if(parent[node]!=node){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        min.assign(n, -1);

        for(int i=0; i<n; i++){
            parent[i]=i;
        }

        for(int i=0; i<edges.size(); i++){
            int source = edges[i][0], target = edges[i][1], weight = edges[i][2];
            int sourceRoot = find(source);
            int targetRoot = find(target);

            if (min[sourceRoot] == -1) min[sourceRoot] = weight;
            else min[sourceRoot] &= weight;

            if (min[targetRoot] == -1) min[targetRoot] = weight;
            else min[targetRoot] &= weight;

            if (sourceRoot != targetRoot) {
                parent[sourceRoot] = targetRoot;
                min[targetRoot] &= min[sourceRoot];
            }
        }
        vector<int> result;
        for (int i=0; i<query.size(); i++) {
            int start = query[i][0], end = query[i][1];

            if (start == end) result.push_back(0);
            else if (find(start) != find(end)) result.push_back(-1);
            else result.push_back(min[find(start)]);
        }
        return result;
    }
};