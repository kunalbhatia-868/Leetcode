//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void addToSortedStack(stack<int>& s, int val)
{
    
    if(s.empty())
    {
        s.push(val);
        return;
    }
    
    
    int top=s.top();
    if(top>val)
    {
        s.pop();
        addToSortedStack(s,val);
        s.push(top);
    }
    else{
        s.push(val);
        return;
    }
}

void SortedStack :: sort()
{
   //Your code here
   if(this->s.size()<=1){
       return;
   }
   
   int top=this->s.top();
   this->s.pop();
   sort();
   addToSortedStack(this->s,top);
   
   
}