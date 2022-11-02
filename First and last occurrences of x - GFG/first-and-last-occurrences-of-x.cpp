//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int lowerBound(int arr[],int n,int x)
{
    int l=0;
    int h=n-1;
    
    while(l<=h)
    {
        int m=l+(h-l)/2;
        
        if(arr[m]<x)
        {
            l=m+1;        
        }
        else
        {
            h=m-1;
        }
    }
    
    if(arr[h+1]==x){
        return h+1;
    }
    else{
        return -1;
    }
}

int upperBound(int arr[],int n,int x)
{
    int l=0;
    int h=n-1;
    
    while(l<=h)
    {
        int m=l+(h-l)/2;
        
        if(arr[m]<=x)
        {
            l=m+1;        
        }
        else
        {
            h=m-1;
        }
    }
    
    if(arr[h]==x){
        return h;
    }
    else{
        return -1;
    }
}


vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> output={-1,-1};
    if(arr[0]>x || arr[n-1]<x || n==0)
    {
        return output;
    }
    
    output[0]=lowerBound(arr,n,x);
    output[1]=upperBound(arr,n,x);
    return output;
    
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