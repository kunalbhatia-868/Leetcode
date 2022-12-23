//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col,int n, int m, vector<vector<int>>& mat,vector<vector<int>>& vis)
    {
        
        mat[row][col]=0;
        
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<4;i++){
            int r=row+dir[i][0];
            int c=col+dir[i][1];
            
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && mat[r][c]==1){
                vis[r][c]=1;
                dfs(r,c,n,m,mat,vis);
            }
        }
        
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> output=grid;
        
        //first and last row
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1){
                    if(!vis[i][j] && grid[i][j]==1){
                        vis[i][j]=1;
                        dfs(i,j,n,m,output,vis);
                    }
                }
            }
        }
        
        //first and last col
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0 || j==m-1){
                    if(!vis[i][j] && grid[i][j]==1){
                        vis[i][j]=1;
                        dfs(i,j,n,m,output,vis);
                    }
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(output[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends