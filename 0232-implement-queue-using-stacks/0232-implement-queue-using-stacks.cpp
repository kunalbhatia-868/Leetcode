class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.size()==0){
            st.push(x);
            return;
        }
        int top=st.top();
        st.pop();
        this->push(x);
        st.push(top);
    }
    
    int pop() {
        if(st.size()==0){
            return -1;
        }
        int top=st.top();
        st.pop();
        return top;
    }
    
    int peek() {
        if(st.size()==0){
            return -1;
        }
        return st.top();
    }
    
    bool empty() {
        return st.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */