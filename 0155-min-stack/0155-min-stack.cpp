class MinStack {
public:
    stack<long long> st;
    long long minValue;
    MinStack() {
        
    }
    
    void push(long long val) {
        if(st.empty()){
           minValue=val;
           st.push(val);
            return;
        }
        
        if(val<minValue){
            st.push(2*val-minValue);
            minValue=val;
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.top()<minValue){
            minValue=2*minValue-st.top();
        }
        st.pop();        
        
    }
    
    int top() {
        if(st.top()<minValue){
            return minValue;
        }
        else{
            return st.top();
        }
    }
    
    int getMin() {
        return minValue;   
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