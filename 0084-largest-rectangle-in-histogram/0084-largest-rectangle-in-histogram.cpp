class Solution {
public:
    vector<int> SmallerRightElement(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> output(n);
        stack<int> st;
        st.push(n-1);
        output[n-1]=n;
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && nums[i]<=nums[st.top()])
            {
                st.pop();
            } 
            
            if(st.empty()){
                output[i]=n;
            }
            else{
                output[i]=st.top();
            }
            st.push(i);
        }
        
        return output;
    }
    vector<int> SmallerLeftElement(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> output(n);
        stack<int> st;
        st.push(0);
        output[0]=-1;
        
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && nums[i]<=nums[st.top()])
            {
                st.pop();
            } 
            
            if(st.empty()){
                output[i]=-1;
            }
            else{
                output[i]=st.top();
            }
            st.push(i);
        }
        
        return output;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> gre=SmallerRightElement(heights);
        vector<int> gle=SmallerLeftElement(heights);
        
        int maxArea=INT_MIN;
        for(int i=0;i<gle.size();i++){
            int area=(gre[i]-gle[i]-1)*heights[i];
            // area of current index height
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};