//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int Key) {
        // Code here
        int start=0;
        int end=A.size()-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(A[mid]==Key)
            {
                return 1;
            }
            
            if(A[mid]>=A[start])   //left is sorted
            {
                if(A[mid]>Key && A[start]<=Key)
                {
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }   
            else    //right is sorted
            {
                if(A[mid]<Key && A[end]>=Key)
                {
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends