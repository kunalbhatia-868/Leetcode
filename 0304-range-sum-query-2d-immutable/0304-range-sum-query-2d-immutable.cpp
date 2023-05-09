class NumMatrix {
public:
    vector<vector<int>> matSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        matSum=vector<vector<int>>(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    matSum[i][j]=matrix[i][j];
                }
                else if(i==0){
                    matSum[i][j]=matSum[i][j-1]+matrix[i][j];
                }
                else if(j==0){
                    matSum[i][j]=matSum[i-1][j]+matrix[i][j];
                }
                else{
                    matSum[i][j]=matrix[i][j]+matSum[i-1][j]+matSum[i][j-1]-matSum[i-1][j-1];
                }
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int n=matSum[row2][col2];
        if(col1>0 && row1>0){
            n+=matSum[row1-1][col1-1];
        }
        if(col1>0){
            n-=matSum[row2][col1-1];
        }
        if(row1>0){
            n-=matSum[row1-1][col2];
        }
        return n;
        return n;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */