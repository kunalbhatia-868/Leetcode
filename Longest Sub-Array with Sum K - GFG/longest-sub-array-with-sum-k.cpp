//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int,int> nMap;
        nMap[0]=-1;
        
        int maxLen=0;
        int currSum=0;
        for(int i=0;i<N;i++)
        {
            currSum+=A[i];
            
            if(nMap.count(currSum-K))
            {
                maxLen=max(maxLen,i-nMap[currSum-K]);
            }
            
            if(!nMap.count(currSum)){
                nMap[currSum]=i;
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