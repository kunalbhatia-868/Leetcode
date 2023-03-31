class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        // rotate = transpose(row to cols and vice verse) + mirror your matrix(col 1,2 as col 3,4)
        
        int n=matrix.size();
        
        // transpose
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        
        // mirror col 
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};