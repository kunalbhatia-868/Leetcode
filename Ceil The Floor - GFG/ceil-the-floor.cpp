//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    
    pair<int,int> fc;
    int f=INT32_MIN,c=INT32_MAX;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x){
            f=arr[i];
            c=arr[i];
            break;
        }
        else if(arr[i]<x)
        {
            f=max(f,arr[i]);
        }
        else if(arr[i]>x){
            c=min(c,arr[i]);
        }
    }
    
    fc.first=f==INT32_MIN?-1:f;
    fc.second=c==INT32_MAX?-1:c;
    return fc;
}