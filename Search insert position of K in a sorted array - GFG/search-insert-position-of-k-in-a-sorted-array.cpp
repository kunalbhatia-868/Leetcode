//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int pos=N;
        int l=0;
        int h=N-1;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(Arr[m]==k)
            {
                return m;
            }
            else if(Arr[m]<k)
            {
                l=m+1;
            }
            else{
                pos=m;
                h=m-1;
            }
        }
        return pos;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends