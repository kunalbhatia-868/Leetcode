class MyStack {
    queue<int> q1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int n=q1.size();
        q1.push(x);
        
        while(n--){
            int top=q1.front();
            q1.pop();
            q1.push(top);
        }
    }
    
    int pop() {
        if(q1.size()==0){
            return -1;
        }
        int top=q1.front();
        q1.pop();
        return top;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size()==0;
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