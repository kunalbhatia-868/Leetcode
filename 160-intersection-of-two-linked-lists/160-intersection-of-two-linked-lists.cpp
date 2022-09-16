/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: 
    int length(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=length(headA);
        int l2=length(headB);
        
        int diff=abs(l2-l1);
        
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        
        if(l1>l2)
        {
            while(diff>0)
            {
                temp1=temp1->next;
                diff--;
            }    
        }
        else
        {
            while(diff>0)
            {
                temp2=temp2->next;
                diff--;
            }
        }
        while(temp1 != temp2)
        {
            if(temp1==NULL && temp2==NULL){
                break;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
        
    }
};