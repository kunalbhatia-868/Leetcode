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

// 1 2 3 4 5 NULL


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;        
        ListNode* fast=head;

        int i=0;
        while(fast && fast ->next)
        {
            fast=fast->next;
            
            if(i>=n)
            {
                slow=slow->next;
            }
            i++;
        }
        
        if(i==n-1){
            return head->next;
        }
        
        slow->next=slow->next->next;
        return head;
    }
};