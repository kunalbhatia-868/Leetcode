//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int matSize=a.size()*a[0].size();
        
        int r=0,c=0,curr=0;
        int rm=a.size()-1,cm=a[0].size()-1;
        
        while(curr<matSize)
        {
            for(int i=c;i<=cm && curr<matSize;i++)
            {
                curr++;
                if(curr==k){
                    return a[r][i]; 
                }
                
            }
            r++;
            for(int i=r;i<=rm && curr<matSize;i++)
            {
                curr++;
                if(curr==k){
                    return a[i][cm]; 
                }
                
            }
            cm--;
        
            for(int i=cm;i>=c && curr<matSize;i--)
            {
                curr++;
                if(curr==k){
                    return a[rm][i]; 
                }
                
            }
            rm--;
            
            for(int i=rm;i>=r && curr<matSize;i--)
            {
                curr++;
                if(curr==k){
                    return a[i][c]; 
                }
            }
            c++;   
        }
        
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends