//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    //finding min element index
	    if(n==1){
            return 0;
        } 
	    
	    int start=0;
        int end=n-1;
        
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(arr[start]<arr[end])     // already sorted
            {
                return start;
            }
            
            if(arr[mid]<arr[(mid+1)%n] && arr[mid]<arr[(mid+n-1)%n])
            {
                return mid;
            }
            
            if(arr[start]<=arr[mid])     //left sorted 
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return -1;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends