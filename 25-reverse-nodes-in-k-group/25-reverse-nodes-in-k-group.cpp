/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseK(ListNode* head,int k)
    {
        int i=0;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr != NULL && i<k)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        
        int i=0;
        ListNode* temp=curr;
        while(i<k && temp){
            temp=temp->next;
            i++;
        }
        
        if(i!=k){
            return head; 
        }
        
        ListNode* newHead=reverseK(head,k);
        curr->next=reverseKGroup(temp,k);
            
        return newHead;
    }
};