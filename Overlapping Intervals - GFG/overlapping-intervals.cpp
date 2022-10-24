//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin(),intervals.end(),comp);
         vector<vector<int>> output;
         int start=intervals[0][0];
         int end=intervals[0][1];
         int i=1;
         while(i<intervals.size())
         {
             if(intervals[i][0]>end){
                output.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
             }
             else
             {
                end=max(end,intervals[i][1]); 
             }
             i++;
         }
         output.push_back({start,end});
         return output;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends