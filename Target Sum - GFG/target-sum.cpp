//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int total=0;

        for(int i=0;i<A.size();i++){
            total+=A[i];
        }

        
        if(target>total || target<-total || (total+target)%2!=0){
            return 0;
        }

        // as s1-s2=tar && s1+s2==total
        // s1=(total+tar)/2
        // Now find no of subsets with sum==(total+tar)/2

        int k=(total+target)/2;
        int n=A.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<k+1;j++){
                if(i==0){
                    dp[i][j]=j==0?1:0;
                }
                else{
                    if(A[i-1]<=j){
                        dp[i][j]=dp[i-1][j] + dp[i-1][j-A[i-1]];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][k];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends