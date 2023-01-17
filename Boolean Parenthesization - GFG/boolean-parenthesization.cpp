//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
    int countWays(string& s,int i,int j,bool isTrue){
        if(i>j){
            return false;
        }
        if(i==j){
            if(isTrue){
                dp[i][j][isTrue]=s[i]=='T';
                return s[i]=='T';
            }
            else{
                dp[i][j][isTrue]=s[i]=='F';
                return s[i]=='F';
            }
        }
        
        if(dp[i][j][isTrue]!=-1){
            return dp[i][j][isTrue];
        }
        
        int ways=0;
        for(int k=i+1;k<j;k+=2)
        {
            int lt=countWays(s,i,k-1,true);
            int lf=countWays(s,i,k-1,false);
            int rt=countWays(s,k+1,j,true);
            int rf=countWays(s,k+1,j,false);
            
            if(s[k]=='&')
            {
                if(isTrue){
                    ways+=lt*rt;
                }
                else{
                    ways+=lt*rf + lf*rt + lf*rf;
                }
            }
            else if(s[k]=='|')
            {
                if(isTrue){
                    ways+=lt*rf + lf*rt + lt*rt;
                }
                else{
                    ways+=lf*rf;
                }
            }
            else if(s[k]=='^')
            {
                if(isTrue){
                    ways+=lt*rf + lf*rt;
                }
                else{
                    ways+=lf*rf + lt*rt;
                }
            } 
        }
        dp[i][j][isTrue]=ways%1003;
        return dp[i][j][isTrue];
    }
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return countWays(S,0,N-1,true);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends