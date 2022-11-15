//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    public:
    int leftbound(vector<long long> v, long long x)
    {
        if(v[0]==x){
            return 0;
        }
        
        int left=0;
        int right=v.size()-1;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            
            if(v[mid]>=x)
            {
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        
        if(right==v.size()-1 || v[right+1]!=x){
            return -1;
        }
        else{
            return right+1;
        }
    }
    
    int rightbound(vector<long long> v, long long x)
    {
        if(v[v.size()-1]==x){
            return v.size()-1;
        }
        
        int left=0;
        int right=v.size()-1;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            
            if(v[mid]<=x)
            {
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return v[left-1]==x?left-1:-1;
        if(left==0 || v[left-1]!=x){
            return -1;
        }
        else{
            return left-1;
        }
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        return {leftbound(v,x),rightbound(v,x)};
        
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends