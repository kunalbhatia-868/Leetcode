//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> output;
    	deque<int> dq;
    
    	for(int i=0;i<n;i++){
    		while(dq.size()>0 && arr[dq.back()]<arr[i]){
    			dq.pop_back();
    		}
    		dq.push_back(i);
    		if(i>=k-1){
    			if(dq.size()>0 && dq.front()<=i-k){
    				dq.pop_front();
    			}		
    			output.push_back(arr[dq.front()]);
    		}
    	}

    	return output;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends