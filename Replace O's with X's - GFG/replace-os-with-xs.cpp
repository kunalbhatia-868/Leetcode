//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void dfs(int row, int col,int n, int m, vector<vector<char>>& mat,vector<vector<char>>& output,vector<vector<int>>& vis)
    {
        
        output[row][col]='O';
        
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<4;i++){
            int r=row+dir[i][0];
            int c=col+dir[i][1];
            
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && mat[r][c]=='O'){
                vis[r][c]=1;
                dfs(r,c,n,m,mat,output,vis);
            }
        }
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<char>> output(n,vector<char>(m,'X'));
        
        //first and last row
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1){
                    if(!vis[i][j] && mat[i][j]=='O'){
                        vis[i][j]=1;
                        dfs(i,j,n,m,mat,output,vis);
                    }
                }
            }
        }
        
        //first and last col
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0 || j==m-1){
                    if(!vis[i][j] && mat[i][j]=='O'){
                        vis[i][j]=1;
                        dfs(i,j,n,m,mat,output,vis);
                    }
                }
            }
        }
        
        return output;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends