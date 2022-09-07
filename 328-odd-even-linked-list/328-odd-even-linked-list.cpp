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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* odd=head;
        ListNode* op=head;
        ListNode* even=head->next;
        ListNode* ep=head->next;
        
        int n=3;
        ListNode* temp=head->next->next;
        while(temp != NULL)
        {
            if(n%2==0)
            {
                ep->next=temp;
                ep=temp;
            }
            else
            {
                op->next=temp;
                op=temp;
            }
            temp=temp->next;
            n++;
        }
        op->next=even;
        ep->next=NULL;
        return odd;
    }
};