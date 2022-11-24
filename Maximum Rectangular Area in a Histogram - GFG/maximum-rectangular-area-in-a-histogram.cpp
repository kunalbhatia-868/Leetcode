//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> NearestShorterLeft(long long heights[], int n){
        vector<long long> output;
        stack<long long> st;
        for(int i=0;i<n;i++)
        {
            long long curr=heights[i];
            if(st.size()==0){
                output.push_back(-1);
            }
            else if(heights[st.top()]>=curr){
                while(!st.empty() && heights[st.top()]>=curr){
                    st.pop();
                }
                
                if(st.size()==0){
                    output.push_back(-1);
                }
                else{
                    output.push_back(st.top());
                }
            }
            else if(heights[st.top()]<curr){
                output.push_back(st.top());
            }
            st.push(i);
        }
        return output;
    }
    vector<long long> NearestShorterRight(long long heights[], int n){
        vector<long long> output(n);
        stack<long long> st;
        for(int i=n-1;i>=0;i--)
        {
            long long curr=heights[i];
            if(st.size()==0){
                output[i]=n;
            }
            else if(heights[st.top()]>=curr){
                while(!st.empty() && heights[st.top()]>=curr){
                    st.pop();
                }
                
                if(st.size()==0){
                    output[i]=n;
                }
                else{
                    output[i]=st.top();
                }
            }
            else if(heights[st.top()]<curr){
                output[i]=st.top();
            }
            st.push(i);
        }
        return output;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> nsr=NearestShorterRight(arr,n);
        vector<long long> nsl=NearestShorterLeft(arr,n);
        
        long long maxArea=INT32_MIN;
        
        for(int i=0;i<n;i++)
        {
            
            long long width=nsr[i]-nsl[i]-1;
            long long area=arr[i]*width;
            
            maxArea=max(maxArea,area);
        }
        
        return maxArea;
        
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends