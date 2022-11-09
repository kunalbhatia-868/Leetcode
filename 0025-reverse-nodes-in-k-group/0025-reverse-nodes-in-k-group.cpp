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
    ListNode* reverseFirstK(ListNode* head, int k){
        int i=0;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(i<k)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        
        head->next=curr;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i=0;
        ListNode* temp=head;
        
        while(i<k && temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        
        if(i!=k){
            return head;
        }
        
        ListNode* rest=reverseKGroup(temp,k);
        ListNode* newHead=reverseFirstK(head,k);
        head->next=rest;
        return newHead;
    }
};