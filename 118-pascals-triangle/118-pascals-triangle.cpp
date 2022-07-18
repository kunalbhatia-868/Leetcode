class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        for(int i=0;i<numRows;i++)
        {
            vector<int> row;
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(output[i-1][j-1]+output[i-1][j]);
                }
            }
            output.push_back(row);
        }
        return output;
    }
};