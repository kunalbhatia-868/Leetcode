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
        ListNode* t1=list1;
        ListNode* t2=list2;
        
        ListNode* nhead=NULL;
        ListNode* ntail=NULL;
        
        while(t1 && t2){
            if(t1->val<t2->val){
                if(nhead==NULL){
                    nhead=t1;
                    ntail=t1;
                }
                else{
                    ntail->next=t1;
                    ntail=t1;
                }
                t1=t1->next;
            }
            else{
                if(nhead==NULL){
                    nhead=t2;
                    ntail=t2;
                }
                else{
                    ntail->next=t2;
                    ntail=t2;
                }
                t2=t2->next;
            }
        }
        
        if(t1){
            if(nhead==NULL){
                    nhead=t1;
                    ntail=t1;
                }
                else{
                    ntail->next=t1;
                    ntail=t1;
                }
        }
        
        if(t2){
            if(nhead==NULL){
                    nhead=t2;
                    ntail=t2;
                }
                else{
                    ntail->next=t2;
                    ntail=t2;
                }
        }
        
        return nhead;
    }
};