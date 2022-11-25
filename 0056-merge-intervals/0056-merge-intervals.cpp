class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        stack<vector<int>> st;    
        sort(intervals.begin(),intervals.end(),comp);
        
        for(int i=0;i<intervals.size();i++)
        {
            if(st.empty() || st.top()[1]<intervals[i][0]){
                st.push(intervals[i]);
            }
            else{
                //merge
                int start=st.top()[0];
                int end=st.top()[1];
                st.pop();
                st.push({start,max(end,intervals[i][1])});
            }
        }
        
        while(!st.empty()){
            output.push_back(st.top());
            st.pop();
        }
        
        return output;
    }
};