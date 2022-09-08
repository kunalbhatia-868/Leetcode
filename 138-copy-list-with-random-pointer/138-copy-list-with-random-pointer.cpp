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
        Node* nHead=new Node(-1);
        Node* p=nHead;
        while(curr!=NULL)
        {
            Node* newNode=new Node(curr->val);
            p->next=newNode;
            p=p->next;
            
            map[curr]=newNode;
            curr=curr->next;
        }
        
        nHead=nHead->next;
        curr=head;
        p=nHead;
        
        while(curr!=NULL)
        {
            if(curr->random==NULL)
            {
                p->random=NULL;
            }
            else
            {
                p->random=map[curr->random];
            }
            p=p->next;
            curr=curr->next;
        }
    
        return nHead;
    }
};