class Solution {
public:
    vector<int> NearestShorterLeft(vector<int>& heights){
        vector<int> output;
        stack<int> st;
        for(int i=0;i<heights.size();i++)
        {
            int curr=heights[i];
            if(st.size()==0){
                output.push_back(-1);
            }
            else if(heights[st.top()]>=curr){
                while(!st.empty() && heights[st.top()]>=curr){
                    st.pop();
                }
                
                if(st.size()==0){
                    output.push_back(-1);
                }
                else{
                    output.push_back(st.top());
                }
            }
            else if(heights[st.top()]<curr){
                output.push_back(st.top());
            }
            st.push(i);
        }
        return output;
    }
    vector<int> NearestShorterRight(vector<int>& heights){
        vector<int> output(heights.size());
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--)
        {
            int curr=heights[i];
            if(st.size()==0){
                output[i]=heights.size();
            }
            else if(heights[st.top()]>=curr){
                while(!st.empty() && heights[st.top()]>=curr){
                    st.pop();
                }
                
                if(st.size()==0){
                    output[i]=heights.size();
                }
                else{
                    output[i]=st.top();
                }
            }
            else if(heights[st.top()]<curr){
                output[i]=st.top();
            }
            st.push(i);
        }
        return output;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsr=NearestShorterRight(heights);
        vector<int> nsl=NearestShorterLeft(heights);
        
        int maxArea=INT32_MIN;
        
        for(int i=0;i<heights.size();i++)
        {
            
            int width=nsr[i]-nsl[i]-1;
            int area=heights[i]*width;
            
            maxArea=max(maxArea,area);
        }
        
        return maxArea;
    }
};