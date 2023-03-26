//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item& a,Item& b){
        double awt=a.weight;
        double aval=a.value;
        double bwt=b.weight;
        double bval=b.value;
        
        // per unit val -> pv
        double apv=aval/awt;
        double bpv=bval/bwt;
        
        return apv>bpv;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        
        double maxVal=0;
        for(int i=0;i<n;i++){
            double currWt=arr[i].weight;
            double currVal=arr[i].value;
            if(currWt<W){
                W-=currWt;
                maxVal+=currVal;
            }
            else{
                maxVal+=(W*(currVal/currWt));
                W=0;
                break;
            }
        }
        return maxVal;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends