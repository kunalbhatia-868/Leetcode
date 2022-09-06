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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;        
        ListNode* fast=head;
        
        while(fast != nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* mid=slow;
        
        ListNode* head2=reverse(mid);
        ListNode* head1=head;
        
        while(head1!=nullptr && head2!=nullptr)
        {
            if(head1->val!=head2->val)
            {
                return false;
            }    
            head1=head1->next;
            head2=head2->next;

        }
        return true;

    }
};