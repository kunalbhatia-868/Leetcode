//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr,int n, int sum,vector<vector<int>>& dp){
        // code here 
        if(sum==0){
            return true;
        }
        else if(n==0){
            return false;
        }
        
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        
        if(arr[n-1]<=sum){      // less than equal to total sum
            dp[n][sum]=isSubsetSum(arr,n-1,sum-arr[n-1],dp) || isSubsetSum(arr,n-1,sum,dp);
        }
        else{                   
            dp[n][sum]=isSubsetSum(arr,n-1,sum,dp);
        }
        return dp[n][sum];
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1)); 
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j==0){
                    dp[i][j]=true;
                }
                else if(i==0){
                    dp[i][j]=false;
                }
                else{
                    if(arr[i-1]<=j){
                        dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends