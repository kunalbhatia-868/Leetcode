//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int helper(int coins[], int n, int target) 
	{ 
	    // Your code goes here 
	    if(target==0){
	        return 0;
	    }
	    else if(n==0){
	        return INT_MAX-1;
	    }
	    
	    if(coins[n-1]<=target){
	        
	        int ifPicked=helper(coins,n,target-coins[n-1]);
	        int ifNotPicked=helper(coins,n-1,target);
	        int ans=min(ifNotPicked,1+ifPicked);
	        return ans;
	        
	    }
	    else{
	        int ifNotPicked=helper(coins,n-1,target);
	        return ifNotPicked;
	    }
	    
	} 
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here 
	    vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
	    for(int i=0;i<M+1;i++){
	        for(int j=0;j<V+1;j++){
	            if(j==0){
	                dp[i][j]=0;
	            }
	            else if(i==0){
	                dp[i][j]=INT_MAX-1;
	            }
	            else{
	                if(coins[i-1]<=j){
	                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
	                }
	                else{
	                    dp[i][j]=dp[i-1][j];
	                }
	            }
	        }
	    }
	    return dp[M][V]==INT_MAX-1?-1:dp[M][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends