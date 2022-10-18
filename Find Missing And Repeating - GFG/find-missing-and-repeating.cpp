//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int* output=new int[2];
        
        // repeating no hare tortoise method
        int rNumber;
        for(int i=0;i<n;i++)
        {
            if(arr[abs(arr[i])-1]>0){
                arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
            }       
            else{
                rNumber=abs(arr[i]);
            }
        }
        
        // missing No
        int mNumber=rNumber;
        for(int i=0;i<n;i++){
            mNumber^=abs(arr[i]);
        }
        for(int i=1;i<=n;i++){
            mNumber^=i;
        }
        
        output[0]=rNumber;
        output[1]=mNumber;
        return output;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends