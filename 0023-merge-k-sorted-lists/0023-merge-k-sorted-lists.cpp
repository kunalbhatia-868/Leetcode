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
    struct compare{
        bool operator()(ListNode* l1,ListNode* l2){
            return l1->val>l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        
        for(auto list:lists){
            if(list){
                pq.push(list);
            }
        }
        
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(!pq.empty()){
            ListNode* top=pq.top();
            pq.pop();
            
            if(head==NULL){
                head=top;
                tail=top;
            }
            else{
                tail->next=top;
                tail=top;
            }
            
            if(top->next !=NULL){
                pq.push(top->next);    
            }
        }
        return  head;
        
    }
};