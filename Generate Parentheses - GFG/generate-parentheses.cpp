//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void generateParenthesis(int ob, int cb,string curr,vector<string>& output)
    {
        if(ob==0 && cb==0)
        {
            output.push_back(curr);    
        }        
            
        if(ob>0)
        {
            generateParenthesis(ob-1,cb,curr+"(",output);
        }
        
        if(cb>ob && cb>0)
        {
            generateParenthesis(ob,cb-1,curr+")",output);
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string> output;
        generateParenthesis(n,n,"",output);
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends