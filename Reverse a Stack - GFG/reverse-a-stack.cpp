//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void sendToBottom(stack<int>& st,int a)
    {
        if(st.empty()){
            st.push(a);
            return;
        }        
        
        
        int top=st.top();
        st.pop();
        sendToBottom(st,a);
        st.push(top);
    }
    void Reverse(stack<int> &St){
        if(St.size()<=1){
            return;
        }
        
        int top=St.top();
        St.pop();
        Reverse(St);
        sendToBottom(St,top);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends