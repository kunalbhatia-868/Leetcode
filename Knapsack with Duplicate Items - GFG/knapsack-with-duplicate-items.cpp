//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapsack(int val[], int wt[],int N, int W,vector<vector<int>>& dp)
    {
        if(W==0 || N==0){
            return 0;    
        }
        
        if(dp[N][W]!=-1){
            return dp[N][W];
        }
        
        if(wt[N-1]<=W){
            dp[N][W]= max(knapsack(val,wt,N-1,W,dp),val[N-1]+knapsack(val,wt,N,W-wt[N-1],dp));
        }
        else{
            dp[N][W]= knapsack(val,wt,N-1,W,dp);
        }
        
        return dp[N][W];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
        knapsack(val,wt,N,W,dp);
        return dp[N][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends