class Router {
public:
    queue<vector<int>> q;
    map<vector<int>, int> pk;
    map<int, vector<int>> des;
    int n;
    Router(int memoryLimit) { n = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> pkt={source, destination, timestamp};
        if (pk.find(pkt) != pk.end()) {
            return false;
        }
        if(q.size()>=n){
            forwardPacket();
        }
        q.push(pkt);
        pk[pkt] = 1;
        des[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if(q.empty()) return {};
        vector<int> ans = q.front();
        q.pop();
        int d=ans[1];
        pk.erase(ans);
        des[d].erase(des[d].begin());
        return ans;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it=des.find(destination);
        vector<int>& v=it->second;
        if(it==des.end() || v.empty()){
            return 0;
        }
        auto left=lower_bound(v.begin(), v.end(), startTime);
        auto right=upper_bound(v.begin(), v.end(), endTime);
        return right-left;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */