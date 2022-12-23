//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>>& vec,int sr,int sc)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vis[row][col]=1;
        vec.push_back({row-sr,col-sc});
        
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<4;i++){
            int r=row+dir[i][0];
            int c=col+dir[i][1];
            
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]==1){
                dfs(r,c,grid,vis,vec,sr,sc);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> set;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    set.insert(vec);
                }
            }
        }
        
        return set.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends