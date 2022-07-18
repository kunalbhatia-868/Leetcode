class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output(numRows);
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    output[i].push_back(1);
                }
                else
                {
                    output[i].push_back(output[i-1][j-1]+output[i-1][j]);
                }
            }
        }
        return output;
    }
};