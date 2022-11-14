class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            int top=q1.front();
            q1.pop();
            q2.push(top);
        }
        while(!q2.empty()){
            int top=q2.front();
            q2.pop();
            q1.push(top);
        }
    }
    
    int pop() {
        if(q1.size()==0)
        {
            return -1;
        }
        
        int top=q1.front();
        q1.pop();
        return top;
    }
    
    int top() {
        if(q1.size()==0)
        {
            return -1;
        }
        
        int top=q1.front();
        return top;
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