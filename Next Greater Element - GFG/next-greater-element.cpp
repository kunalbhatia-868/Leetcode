//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> output(n);
        stack<long long> st;
        for(int i=n-1;i>=0;i--)
        {
            long long curr=arr[i];
            if(st.size()==0){
                output[i]=-1;
                
            }
            else if(st.top()<=curr)
            {
                while(st.size()>0 && st.top()<=curr){
                    st.pop();
                }
                
                if(st.size()==0){
                    output[i]=-1;
                }
                else{
                    output[i]=st.top();
                }
            }
            else{
                output[i]=st.top();
            }
            
            st.push(arr[i]);
        }
        return output;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends