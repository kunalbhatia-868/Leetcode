//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void floodFill(vector<vector<int>>& image, int sr, int sc,vector<vector<int>>& visited, int color) {
        visited[sr][sc]=1;
        int initialColor=image[sr][sc];
        image[sr][sc]=color;

        vector<vector<int>> coordinates={{-1,0},{0,1},{1,0},{0,-1}};

        for(int i=0;i<coordinates.size();i++){
            int r=sr+coordinates[i][0];
            int c=sc+coordinates[i][1];

            if(r>=0 && c>=0 && r<image.size() && c<image[0].size() && image[r][c]==initialColor && visited[r][c]==0){
                floodFill(image,r,c,visited,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> output=image;
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        floodFill(output,sr,sc,visited,newColor);
        return output;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends