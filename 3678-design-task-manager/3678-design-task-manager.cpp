class TaskManager {
public:
unordered_map<int, pair<int, int>> m;
priority_queue<pair<int, int>> p;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto t: tasks){
            add(t[0], t[1], t[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        p.push({priority,taskId});
        m[taskId]={priority,userId};
    }
    
    void edit(int taskId, int newPriority) {
        m[taskId].first=newPriority;
        p.push({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        m.erase(taskId);
    }
    
    int execTop() {
        while(!p.empty()){
            int pr=p.top().first, tid=p.top().second;
            if(m.count(tid)>0 && m[tid].first == pr){
                int uid=m[tid].second;
                m.erase(tid);
                return uid;
            }
            p.pop();
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */