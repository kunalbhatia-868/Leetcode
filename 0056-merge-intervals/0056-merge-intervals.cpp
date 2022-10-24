class Solution {
public:
     static bool comp(vector<int>& a,vector<int>& b)
    {
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        sort(intervals.begin(),intervals.end(),comp);
   
        int start=intervals[0][0];
        int end=intervals[0][1];
        
        int i=1;
        while(i<intervals.size())
        {
            if(intervals[i][0]>end)
            {
                output.push_back({start,end});
                start=intervals[i][0];                
                end=intervals[i][1];

            }
            else
            {
                end=max(end,intervals[i][1]);
            }
            i++;
        }
        output.push_back({start,end});
        return output;
    }
};