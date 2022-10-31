//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int start=0,zeroes=0,ones=0,i=0,maxOnes=0;
        
        while(i<n)   
        {
            if(arr[i]==1)
            {
                ones++;
                maxOnes=max(maxOnes,zeroes+ones);
            }
            else
            {
                if(zeroes<m){
                    zeroes++;
                    maxOnes=max(maxOnes,zeroes+ones);
                }
                else
                {
                    while(arr[start]!=0)
                    {
                        start++;
                        ones--;
                    }   
                    start++;
                }
            }
            i++;
        }
        
        return maxOnes;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends