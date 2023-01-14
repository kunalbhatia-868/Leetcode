//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string str, int n) { 
    //complete the function here 
            string str1=str;
            reverse(str.begin(),str.end());
            string str2=str;
            //lcs of str,rev(str)
		    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
		    for(int i=0;i<n+1;i++){
		        for(int j=0;j<n+1;j++){
	                if(i==0 || j==0){
	                    dp[i][j]=0;
	                } 
	                else{
	                    if(str1[i-1]==str2[j-1]){        
	                        dp[i][j]=1+dp[i-1][j-1];
	                    }
	                    else{
	                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	                    }
	                }
		        }    
		    }
            // No of insertion= total char -LCS(str,rev(str))
            // eg leetcode,edocteel -> lcs=ete heighest common part else we need to insert to amke palindrome
            // 8-3->5 hance 5 insertions needed
            int lcs=dp[n][n];
            return n-lcs;
} 