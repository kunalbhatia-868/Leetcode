//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(this->s.empty()){
               return -1;
           }
           return this->minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(this->s.empty()){
               return -1;
           }
           
           int popVal=-1;
           if(this->s.top()<this->minEle){
               popVal=this->minEle;
               this->minEle=2*this->minEle-this->s.top();
           }
           else{
               popVal=this->s.top();
           }
           s.pop();
           return popVal;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(this->s.empty()){
               this->s.push(x);
               minEle=x;
               return ;
           }
           
           if(x<this->minEle){
               this->s.push(2*x - this->minEle);
               this->minEle=x;
           }
           else{
               this->s.push(x);
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends