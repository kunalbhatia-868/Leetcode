class Solution {
public:
    int uniquePaths(vector<vector<int>>& mat,int r, int c,vector<vector<int>>& dp){
        int n=mat.size();
        int m=mat[0].size();
        
        if(r>=n || r<0 || c>=m || c<0 || mat[r][c]==1){
            return 0;
        }
        
        if(r==n-1 && c==m-1){
            return 1;
        }
        
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        
        dp[r][c]=uniquePaths(mat,r+1,c,dp)+uniquePaths(mat,r,c+1,dp);
        return dp[r][c];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return uniquePaths(obstacleGrid,0,0,dp);
    }
};