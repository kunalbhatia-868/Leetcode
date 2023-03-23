class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid,int r,int c,int er,int ec,int cc,int tc,vector<vector<int>>& vis)     {
        int n=grid.size();
        int m=grid[0].size();
        
        if(r>=n || r<0 || c>=m || c<0 || grid[r][c]==-1 || vis[r][c]){
            return 0;
        }
        
        if(r==er && c==ec && cc-1==tc){     //subract this  final cell as it is end cell not empty
            return 1;
        }
        
        vis[r][c]=1;
        int totalPaths=0;
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<dir.size();i++){
            int rn=r+dir[i][0];
            int rc=c+dir[i][1];
            totalPaths+=uniquePaths(grid,rn,rc,er,ec,cc+1,tc,vis);
        }
        vis[r][c]=0;
        return totalPaths;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int freeCell=0,sr,sc,er,ec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    freeCell++;
                }
                else if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                }
                else if(grid[i][j]==2){
                    er=i;
                    ec=j;
                }
            }
        }
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        return uniquePaths(grid,sr,sc,er,ec,0,freeCell,vis);
    }
};