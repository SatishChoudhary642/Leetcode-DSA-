class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector <vector <int>> graph (n);
        unordered_set <int> visited;
        int cnt=0;

        for(int i=0 ;i<edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int node=0; node<n; node++){
            if(visited.count(node)) continue;

            int node_edge[2] = {0, 0};
            dfs(node, graph, visited, node_edge);
            int node_cnt=node_edge[0], edge_cnt=node_edge[1];
            if(node_cnt*(node_cnt-1)==edge_cnt){
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(int curr, vector<vector<int>>& graph, unordered_set<int>& visited,
             int node_edge[2]) {
            visited.insert(curr);
            node_edge[0]++; 
            node_edge[1] += graph[curr].size(); 

            for (int next : graph[curr]) {
                if (!visited.count(next)) {
                    dfs(next, graph, visited, node_edge);
                }
            }
        }
};