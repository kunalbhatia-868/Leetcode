//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        
        Node* evenHead=NULL;
        Node* evenTail=NULL;
        Node* oddHead=NULL;
        Node* oddTail=NULL;
        
        Node* temp=head;
        
        while(temp!=NULL)
        {
            if(temp->data%2==0)
            {
                if(evenHead==NULL)
                {
                    evenHead=temp;
                    evenTail=temp;
                }
                else
                {
                    evenTail->next=temp;
                    evenTail=temp;
                }
            }
            else
            {
                if(oddHead==NULL)
                {
                    oddHead=temp;
                    oddTail=temp;
                }
                else
                {
                    oddTail->next=temp;
                    oddTail=temp;
                }
            }
            temp=temp->next;
        }
        
        if(evenHead)
        {
            evenTail->next=oddHead;
            if(oddHead){
                oddTail->next=NULL;
            }
            return evenHead;
        }
        else
        {
            return oddHead;
        }
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends