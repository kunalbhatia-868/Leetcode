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
    ListNode* reverseK(ListNode* root,int k=INT32_MAX)
    {
        ListNode* curr=root;
        ListNode* prev=NULL;
        int i=0;
        while(i<k && curr!=NULL)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        return prev;
    }
    int getSize(ListNode* head)
    {
        ListNode*temp=head;
        int count=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int size=getSize(head);
        k=k%size;
        
        if(k==0){
            return head;
        }
        
        
        
        ListNode* tempHead=reverseK(head);
        int i=0;
        ListNode* temp=tempHead;
        while(i<k){
            temp=temp->next;
            i++;
        }
        
        ListNode* newHead=reverseK(tempHead,k);
        ListNode* restHead=reverseK(temp);
        
        tempHead->next=restHead;
        return newHead;
    }
};