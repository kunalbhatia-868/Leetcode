class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> output;
        
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=end)
            {
                if(intervals[i][1]>end)
                {
                    end=intervals[i][1];
                }    
            }
            else
            {
                output.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        output.push_back({start,end});
        
        return output;
    }
};