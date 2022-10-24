class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int matSize=matrix.size()*matrix[0].size();
        
        int r=0,c=0,k=0;
        int rm=matrix.size()-1,cm=matrix[0].size()-1;
        
        while(k<matSize)
        {
            for(int i=c;i<=cm && k<matSize;i++)
            {
                output.push_back(matrix[r][i]);
                k++;
                
            }
            r++;
            for(int i=r;i<=rm && k<matSize;i++)
            {
                output.push_back(matrix[i][cm]);
                k++;
                
            }
            cm--;
        
            for(int i=cm;i>=c && k<matSize;i--)
            {
                output.push_back(matrix[rm][i]);
                k++;
                
            }
            rm--;
            
            for(int i=rm;i>=r && k<matSize;i--)
            {
                output.push_back(matrix[i][c]);
            k++;
            }
            c++;   
        }
        
        return output;
    }
};