class Solution {
public:
    // basic question of greater element to the right twisted
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> output(n);
        output[n-1]=0;
        stack<int> st;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            
            if(st.empty())
            {
                output[i]=0;
            }
            else
            {
                output[i]=st.top()-i;
            }
            
            st.push(i);
        }
        
        return output;
    }
};