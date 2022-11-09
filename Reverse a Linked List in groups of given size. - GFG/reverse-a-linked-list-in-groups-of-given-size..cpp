//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node* reverseFirstK(node* head, int k){
        if(head==NULL  || head->next==NULL){
            return head;
        }
        int i=0;
        node* curr=head;
        node* prev=NULL;
        while(i<k && curr!=NULL)
        {
            node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        
        head->next=curr;
        return prev;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head==NULL  || head->next==NULL){
            return head;
        }
        
        int i=0;
        node* temp=head;
        
        while(i<k && temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        
        if(i!=k){
            return reverseFirstK(head,k);
        }
        
        node* rest=reverse(temp,k);
        node* newHead=reverseFirstK(head,k);
        head->next=rest;
        return newHead;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends