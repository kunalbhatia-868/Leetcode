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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        
        ListNode* t1=list1;
        ListNode* t2=list2;
        
        ListNode* newHead=NULL;
        ListNode* newTail=NULL;
        
        while(t1!=NULL && t2!=NULL)
        {
            if(t1->val<t2->val)
            {
                if(newHead==NULL)
                {
                    newHead=t1;
                    newTail=t1;
                }
                else
                {
                    newTail->next=t1;
                    newTail=t1;
                }
                t1=t1->next;
            }
            else
            {
                if(newHead==NULL)
                {
                    newHead=t2;
                    newTail=t2;
                }
                else
                {
                    newTail->next=t2;
                    newTail=t2;
                }
                t2=t2->next;
            }
        }
        
        if(t1!=NULL)
        {
            newTail->next=t1;
        }
        
        if(t2!=NULL)
        {
            newTail->next=t2;
        }
        
        return newHead;
    }
};