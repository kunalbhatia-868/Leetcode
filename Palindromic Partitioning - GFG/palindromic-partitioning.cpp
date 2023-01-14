//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string& str,int i,int j){
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int dia=1;dia<n;dia++)
        {
            for(int i=0,j=dia;j<n;j++,i++){
                if(isPalindrome(str,i,j)){
                    dp[i][j]=0;
                }
                else{
                    int minCuts=INT_MAX;
                    for(int k=i;k<j;k++){
                        int tempCuts=1+dp[i][k]+dp[k+1][j];
                        minCuts=min(minCuts,tempCuts);
                    } 
                    dp[i][j]=minCuts;
                }
            }
        }
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends