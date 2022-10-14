//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void subsetSums(vector<int>& arr, int index,vector<int>& output)
    {
        if(index==arr.size()){
            output.push_back(0);
            return;
        }
        
        subsetSums(arr,index+1,output);
        int n=output.size();
        for(int i=0;i<n;i++)
        {
            output.push_back(arr[index]+output[i]);
        }
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> output;
        subsetSums(arr,0,output);
        return output;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends