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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        
        while(l1!=NULL && l2!=NULL)
        {
            int n=l1->val+l2->val+carry;
            carry=n/10;
            n=n%10;
            
            ListNode* newNode=new ListNode(n);
            if(head==NULL)
            {
                head=newNode;
                tail=newNode;
            }
            else
            {
                tail->next=newNode;
                tail=newNode;
            }
            l1=l1->next;
            l2=l2->next;
        }
        
        if(l1!=NULL)
        {
            if(carry==0)
            {
                tail->next=l1;
            }
            else
            {
                while(l1!=NULL)
                {
                    int n=l1->val+carry;
                    carry=n/10;
                    n=n%10;

                    ListNode* newNode=new ListNode(n);
                    if(head==NULL)
                    {
                        head=newNode;
                        tail=newNode;
                    }
                    else
                    {
                        tail->next=newNode;
                        tail=newNode;
                    }
                    l1=l1->next;
                }
            }
        }
        else if(l2!=NULL)
        {
            if(carry==0)
            {
                tail->next=l2;
            }
            else
            {
                while(l2!=NULL)
                {
                    int n=l2->val+carry;
                    carry=n/10;
                    n=n%10;

                    ListNode* newNode=new ListNode(n);
                    if(head==NULL)
                    {
                        head=newNode;
                        tail=newNode;
                    }
                    else
                    {
                        tail->next=newNode;
                        tail=newNode;
                    }
                    l2=l2->next;
                }
            }
        }
        
        if(carry!=0)
        {
            ListNode* newNode=new ListNode(carry);
            tail->next=newNode;
        }
        return head;
    }
};