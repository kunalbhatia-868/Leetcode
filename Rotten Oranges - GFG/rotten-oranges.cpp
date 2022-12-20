//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        int maxT=0;
        while(!q.empty()){
            int frow=q.front().first.first;
            int fcol=q.front().first.second;
            int ftime=q.front().second;
            q.pop();
            maxT=max(maxT,ftime);
            vector<vector<int>> coordinates={{-1,0},{0,1},{1,0},{0,-1}};

            for(int i=0;i<coordinates.size();i++){
                int r=frow+coordinates[i][0];
                int c=fcol+coordinates[i][1];
    
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1 && vis[r][c]==0){
                    q.push({{r,c},ftime+1});
                    grid[r][c]=2;
                    vis[r][c]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return maxT;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends