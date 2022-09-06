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
        else if(list2==NULL){
            return list1;
        }
        
                
        ListNode* newHead=NULL;
        ListNode* newTail=NULL;
        
        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val<list2->val)
            {
                if(newHead==NULL)
                {
                    newHead=list1;
                    newTail=list1;
                }
                else{
                    newTail->next=list1;
                    newTail=list1;
                }
                list1=list1->next;
            }
            else
            {
                if(newHead==NULL)
                {
                    newHead=list2;
                    newTail=list2;
                }
                else{
                    newTail->next=list2;
                    newTail=list2;
                }
                list2=list2->next;
            }
        }
        
        if(list1!=nullptr)
        {
            newTail->next=list1;
        }
        
        if(list2!=nullptr)
        {
            newTail->next=list2;
        }
        return newHead;
    }
};