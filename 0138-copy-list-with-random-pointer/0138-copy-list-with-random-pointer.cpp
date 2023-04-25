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
        Node* t1=head;
        
        Node* nh=NULL;
        Node* nt=NULL;
        unordered_map<Node*,Node*> listMap;
        while(t1)
        {
            Node* newNode=new Node(t1->val);
            if(nh==NULL){
                nh=newNode;                
                nt=newNode;
            }
            else{
                nt->next=newNode;
                nt=newNode;
            }
            
            listMap[t1]=newNode;
            t1=t1->next;
        }
        
        t1=head;
        while(t1)
        {
            listMap[t1]->random=listMap[t1->random];
            t1=t1->next;
        }
        
        return nh;
    }
};