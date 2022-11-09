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
        
        Node* newHead=NULL;
        Node* newTail=NULL;
        
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* newNode=new Node(temp->val);
            map[temp]=newNode;
            if(newHead==NULL){
                newHead=newNode;
                newTail=newNode;
            }
            else{
                newTail->next=newNode;
                newTail=newNode;
            }
            
            temp=temp->next;
        }
        
        temp=head;
        while(temp){
            map[temp]->random=map[temp->random];
            temp=temp->next;
        }   
        
        return newHead;
    }
};