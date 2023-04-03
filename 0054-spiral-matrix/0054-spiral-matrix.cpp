class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int sr=0,sc=0;
        int er=m-1,ec=n-1;
        int count=0;
        int k=n*m;
        
        vector<int> output;
        while(sr<=er && sc<=ec)
        {
            for(int i=sc;i<=ec && count<k;i++)
            {
                output.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            for(int i=sr;i<=er && count<k;i++){
                output.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            for(int i=ec;i>=sc && count<k;i--)
            {
                output.push_back(matrix[er][i]);
                count++;
            }
            er--;
            for(int i=er;i>=sr && count<k;i--){
                output.push_back(matrix[i][sc]);
                count++;
            }
            sc++; 
        }
        return output;
    }
};