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
    ListNode* prevToMid(ListNode *head)
    {
        ListNode* slow=new ListNode(-1);
        ListNode* fast=new ListNode(-1);
        slow->next=head;
        fast->next=head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* prev=prevToMid(head);
        prev->next=prev->next->next;
        return head;
    }
};