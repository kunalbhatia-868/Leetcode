//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int bst(vector<vector<int>>& arr,int r)
    {
        int l=0;
        int h=arr[0].size()-1;
        int first1=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(arr[r][mid]==1)
            {
                first1=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        if(first1==-1){
            return 0;
        }
        return arr[0].size()-first1;
    }
    
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxOnes=0,maxRow=-1;
	    
	    for(int i=0;i<n;i++)
	    {
	        int rowOnes=bst(arr,i);
	        
	        if(rowOnes>maxOnes){
	            maxOnes=rowOnes;
	            maxRow=i;
	        }
	    }
	    
	    return maxRow;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends