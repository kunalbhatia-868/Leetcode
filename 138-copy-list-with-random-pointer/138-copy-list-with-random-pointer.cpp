/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> map;
        
        Node* curr=head;
        Node* newHead=NULL;
        Node* newTail=NULL;
        while(curr != NULL)
        {
            Node* newNode=new Node(curr->val);
            map[curr]=newNode;
            if(newHead==NULL)
            {
                newHead=newNode;
                newTail=newNode;
            }
            else
            {
                newTail->next=newNode;
                newTail=newNode;
            }
            curr=curr->next;
        }
        
        curr=head;
        while(curr!=NULL)
        {
            if(curr->random)
            {
                map[curr]->random=map[curr->random];
            }
            else
            {
                map[curr]->random=NULL;
            }
            curr=curr->next;
        }
        
        
        return newHead;
        
    }
};