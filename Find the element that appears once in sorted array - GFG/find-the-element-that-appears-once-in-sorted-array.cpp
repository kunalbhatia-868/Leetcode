//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int l=0;
        int h=n-1;
        
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(arr[m]!=arr[m-1] && arr[m]!=arr[m+1])
            {
                return arr[m];
            }
            
            if(m%2==0)
            {
                if(arr[m]==arr[m+1])
                {
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
            else
            {
                if(arr[m]==arr[m-1])
                {
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends