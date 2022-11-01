//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int l=0,h=n-1;
	    int c=n;
	    while(l<=h)
	    {
	        int mid=l+(h-l)/2;
	        if(arr[mid]<=x)
	        {
	            l=mid+1;
	        }
	        else{
	            c=mid;
	            h=mid-1;
	        }
	    }
	    
	    l=0;
	    h=n-1;
	    int f=-1;
	    while(l<=h)
	    {
	        int mid=l+(h-l)/2;
	        if(arr[mid]<x)
	        {
	            f=mid;
	            l=mid+1;
	        }
	        else{
	            h=mid-1;
	        }
	    }
	    
	    return c-f-1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends