//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void combinationSum(vector<int>& candidates, int target,int index, vector<vector<int>>& output,vector<int> temp){
        if(candidates.size()==index)
        {
            if(target==0){
                output.push_back(temp);
            }
            return;
        }
        
        if(index!=0 && candidates[index]==candidates[index-1]){
            combinationSum(candidates,target,index+1,output,temp);
            return;
        }
        
        combinationSum(candidates,target,index+1,output,temp);
        int curr=candidates[index];
        int factor=target/curr;
        for(int i=0;i<factor;i++)
        {        
            target-=curr;
            temp.push_back(curr);
            combinationSum(candidates,target,index+1,output,temp);
        }
        
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        
        sort(A.begin(),A.end());
        vector<vector<int>> output;
        vector<int> temp;
        combinationSum(A,B,0,output,temp);
        int n=output.size();
        for(int i=0;i<n/2;i++)
        {
            temp=output[i];
            output[i]=output[n-i-1];
            output[n-i-1]=temp;
        }
        return output;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends