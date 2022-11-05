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
    ListNode* mergeSortedList(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL){
            return l2;
        }
        else if(l2==NULL){
            return l1;
        }
        
        ListNode* newHead=NULL;
        ListNode* newTail=NULL;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                if(newHead==NULL){
                    newHead=l1;
                    newTail=l1;
                }
                else
                {
                    newTail->next=l1;
                    newTail=l1;
                }
                l1=l1->next;
            }
            else{
                if(newHead==NULL){
                    newHead=l2;
                    newTail=l2;
                }
                else
                {
                    newTail->next=l2;
                    newTail=l2;
                }
                l2=l2->next;
            }
        }
        
        if(l1){
            newTail->next=l1;
        }
        if(l2){
            newTail->next=l2;
        }
        
        return newHead;
    }
    
    ListNode* prevToMid(ListNode *head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* prev=prevToMid(head);
        ListNode* head2=prev->next;
        
        prev->next=NULL;
        
        head=sortList(head);
        head2=sortList(head2);
        ListNode* newHead=mergeSortedList(head,head2);
        return newHead;
    }
};