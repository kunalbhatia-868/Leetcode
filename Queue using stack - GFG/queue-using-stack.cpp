//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        while(input.size()>0){
            int top=input.top();
            input.pop();
            output.push(top);
        }
        input.push(x);
        while(output.size()>0){
            int top=output.top();
            output.pop();
            input.push(top);
        }
    }

    int dequeue() {
        if(input.size()==0){
            return -1;
        }
        int top=input.top();
        input.pop();
        return top;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends