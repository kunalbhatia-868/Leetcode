//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int maxLen=0;
        unordered_map<int,int> numMap;
        numMap[0]=-1;
        
        int currSum=0;
        for(int i=0;i<N;i++)
        {
            currSum+=A[i];
            if(!numMap.count(currSum)){
                numMap[currSum]=i;
            }
            
            if(numMap.count(currSum-K)){
                maxLen=max(maxLen,i-numMap[currSum-K]);
            }
        }
        
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends