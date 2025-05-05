class MinStack {
public:
    int Top;
    vector<int> stack;
    
    MinStack() {
        Top=-1;
    }
    
    void push(int val) {
        Top++;
        stack.push_back(val);
    }
    
    void pop() {
        Top--;
        stack.pop_back();
    }
    
    int top() {
        return stack[Top];
    }
    
    int getMin() {
        return *min_element(stack.begin(), stack.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */