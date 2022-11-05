//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head)
    {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* newHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* temp1=reverse(first);
        Node* temp2=reverse(second);
        
        Node* newHead=NULL;
        Node* newTail=NULL;
        
        int carry=0;
        while(temp1 && temp2)
        {
            int n=temp1->data+temp2->data+carry;
            int rem=n%10;
            carry=n/10;
            
            Node* newNode=new Node(rem);
            if(newHead==NULL){
                newHead=newNode;
                newTail=newNode;
            }
            else{
                newTail->next=newNode;
                newTail=newNode;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        if(temp1)
        {
            if(carry==0)
            {
                newTail->next=temp1;
            }
            else
            {
                while(temp1)
                {
                    int n=temp1->data+carry;
                    int rem=n%10;
                    carry=n/10;
                    
                    Node* newNode=new Node(rem);
                    if(newHead==NULL){
                        newHead=newNode;
                        newTail=newNode;
                    }
                    else{
                        newTail->next=newNode;
                        newTail=newNode;
                    }
                    temp1=temp1->next;
                }
            }
        }
        
        if(temp2)
        {
            if(carry==0)
            {
                newTail->next=temp2;
            }
            else
            {
                while(temp2)
                {
                    int n=temp2->data+carry;
                    int rem=n%10;
                    carry=n/10;
                    
                    Node* newNode=new Node(rem);
                    if(newHead==NULL){
                        newHead=newNode;
                        newTail=newNode;
                    }
                    else{
                        newTail->next=newNode;
                        newTail=newNode;
                    }
                    temp2=temp2->next;
                }
            }
        }
        
        if(carry!=0)
        {
            Node* newNode=new Node(carry);
            newTail->next=newNode;
        }
        
        
        return reverse(newHead);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends