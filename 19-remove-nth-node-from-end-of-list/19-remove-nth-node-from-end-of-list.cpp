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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next != NULL)
        {
            if(i>=n){
                slow=slow->next;
            }
            fast=fast->next;
            i++;
        }
        if(i==n-1){
            return head->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};