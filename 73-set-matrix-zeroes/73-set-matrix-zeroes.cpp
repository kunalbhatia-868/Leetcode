class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row[matrix.size()];
        int column[matrix[0].size()];
        memset(row,0,sizeof(row));
        memset(column,0,sizeof(column));

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=-1;
                    column[j]=-1;
                }
            }
        }
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(row[i]==-1 || column[j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};