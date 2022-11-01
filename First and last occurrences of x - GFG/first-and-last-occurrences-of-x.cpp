//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int lowerBound(int nums[],int n, int target)
    {
        int start=0;
        int end=n-1;
        
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(nums[mid]<target)
            {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        if(nums[end+1]==target)
        {
            return end+1;
        }
        else
        {
            return -1;
        }
    }
    
    int upperBound(int nums[],int n, int target)
    {
        int start=0;
        int end=n-1;
        
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(nums[mid]<=target)
            {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        
        if(nums[start-1]==target)
        {
            return start-1;
        }
        else
        {
            return -1;
        }
    }
vector<int> find(int arr[], int n , int x )
{
    // code here
    int target=x;
    vector<int> range(2,-1);
    if(n==0 || arr[n-1]<target ||arr[0]>target){
        return range;
    }
        
    range[0]=lowerBound(arr,n,target);
    range[1]=upperBound(arr,n,target);
        
    return range;
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends