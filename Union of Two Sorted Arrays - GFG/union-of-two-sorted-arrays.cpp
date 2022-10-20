//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        int i=0;
        int j=0;
        vector<int> output;
        while(i<n && j<m)
        {
            if(arr1[i]==arr2[j]){
                output.push_back(arr1[i]);
                do{
                    i++;
                }while(i<n && arr1[i]==arr1[i-1]);
                
                do{
                    j++;
                }while(j<m && arr2[j]==arr2[j-1]);
            }
            else if(arr1[i]<arr2[j])
            {
                output.push_back(arr1[i]);
                do{
                    i++;
                }while(i<n && arr1[i]==arr1[i-1]);
            }
            else
            {
                output.push_back(arr2[j]);
                do{
                    j++;
                }while(j<m && arr2[j]==arr2[j-1]);
            }
        }
        while(i<n)
        {
            output.push_back(arr1[i]);
            do{
                i++;
            }while(i<n && arr1[i]==arr1[i-1]);
            
        }
        while(j<m)
        {
            output.push_back(arr2[j]);
            do{
                j++;
            }while(j<m && arr2[j]==arr2[j-1]);
        }
        return output;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends