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
    ListNode* prevToMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode* prev=prevToMid(head);
        
        ListNode* h1=head;
        ListNode* h2=prev->next;
        prev->next=NULL;
        h2=reverse(h2);
        
        while(h2)
        {
            ListNode* t1=h1->next;
            ListNode* t2=h2->next;
            h1->next=h2;
            h2->next=t1;
            h1=t1;
            h2=t2;
        }
        
    }
};