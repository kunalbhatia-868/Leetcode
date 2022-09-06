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
    void reorderList(ListNode* head) {
        ListNode* slow=head;        
        ListNode* fast=head;
        
        while(fast != nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* mid=slow;
        
        ListNode* head2=reverse(mid);
        ListNode* head1=head;
        
        while(head1!=NULL && head2!=NULL && head1->next!=NULL && head2->next!=NULL)
        {
            ListNode* temp1=head1->next;
            ListNode* temp2=head2->next;
            head1->next=head2;
            head2->next=temp1;
            head1=temp1;
            head2=temp2;
        }
    }
};