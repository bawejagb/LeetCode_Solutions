class MyStack {
    queue<int> qt;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int sz = qt.size();
        qt.push(x);
        while(sz--){
            qt.push(qt.front());
            qt.pop();
        }
    }
    
    int pop() {
        int val = qt.front();
        qt.pop();
        return val;
    }
    
    int top() {
        return qt.front();
    }
    
    bool empty() {
        return qt.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */